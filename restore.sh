#!/bin/bash

# Ask for the backup file path
echo "Enter the full path to the backup file (e.g., /home/huynguyen/OJ_Backup/docker_backup_YYYYMMDD_HHMMSS.tar.gz):"
read BACKUP_FILE

# Check if the backup file exists
if [[ ! -f "$BACKUP_FILE" ]]; then
    echo "Backup file does not exist. Please check the path."
    exit 1
fi

# Step 1: Create a new volume for MySQL data if it doesn't exist
docker volume create vnoj_mysql_data

# Step 2: Restore the backup
echo "Restoring the backup..."
sudo docker run --rm -v vnoj_mysql_data:/var/lib/mysql -v "$(dirname "$BACKUP_FILE"):/backup" alpine sh -c "tar xzvf /backup/$(basename "$BACKUP_FILE") -C /var/lib/mysql --strip 1"

# Step 3: Run the Docker containers
echo "Starting the MySQL container..."
docker run -d --name vnoj_mysql -v vnoj_mysql_data:/var/lib/mysql -e MYSQL_ROOT_PASSWORD=root -p 3306:3306 mariadb

# Verify the restoration
echo "Verifying restoration..."
docker exec -it vnoj_mysql mariadb -u root -p -e "SHOW DATABASES;"

echo "Restoration completed successfully."

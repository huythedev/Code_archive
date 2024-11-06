#!/bin/bash

# Restore parameters
BACKUP_DIR="/home/huynguyen/OJ_Backup"  # Local backup directory
REMOTE_BACKUP_DIR="Onedrive_MariaDB:/OJ_Backup"  # OneDrive backup folder
BACKUP_FILE="mariadb_backup_DATE.sql.gz"  # Replace DATE with the actual date of the backup
CONTAINER_NAME="vnoj_mysql"
DB_USER="root"
DB_PASSWORD="your_password"  # Replace with your actual password

# Download the backup from OneDrive
echo "Downloading backup from OneDrive..."
rclone copy $REMOTE_BACKUP_DIR/$BACKUP_FILE $BACKUP_DIR

# Check if the download was successful
if [ $? -ne 0 ]; then
    echo "Failed to download backup from OneDrive."
    exit 1
fi

# Decompress the backup file
echo "Decompressing backup file..."
gunzip $BACKUP_DIR/$BACKUP_FILE

# Check if the decompression was successful
if [ $? -ne 0 ]; then
    echo "Failed to decompress backup file."
    exit 1
fi

# Restore the backup to MariaDB
RESTORE_FILE="${BACKUP_FILE%.gz}"  # Remove the .gz extension
echo "Restoring backup to MariaDB..."
docker exec -i $CONTAINER_NAME /usr/bin/mysql -u $DB_USER --password="$DB_PASSWORD" < $BACKUP_DIR/$RESTORE_FILE

# Check if the restoration was successful
if [ $? -eq 0 ]; then
    echo "Backup restored successfully."
    # Optionally, remove the local backup files
    rm $BACKUP_DIR/$RESTORE_FILE
else
    echo "Failed to restore backup."
fi

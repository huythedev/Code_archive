#!/bin/bash

# Define the backup directory and filename
BACKUP_DIR="/home/huynguyen/OJ_Backup"
TIMESTAMP=$(date +"%Y%m%d_%H%M%S")
ARCHIVE_NAME="docker_backup_$TIMESTAMP.tar.gz"
ARCHIVE_PATH="$BACKUP_DIR/$ARCHIVE_NAME"

# Step 1: Create a backup of all Docker volumes
echo "Creating a backup of all Docker volumes..."
sudo docker run --rm --volumes-from vnoj_mysql -v "$BACKUP_DIR:/backup" alpine tar czvf "/backup/$ARCHIVE_NAME" -C /var/lib/mysql .

# Step 2: Upload the backup to OneDrive
echo "Uploading backup to OneDrive..."
rclone copy "$ARCHIVE_PATH" "Onedrive_MariaDB:OJ_Backup"

# Step 3: Remove the local backup file
echo "Removing local backup file..."
rm -f "$ARCHIVE_PATH"

echo "Backup and upload completed successfully."

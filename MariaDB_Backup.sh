#!/bin/bash

# Backup parameters
BACKUP_DIR="/home/huynguyen/OJ_Backup"  # Local backup directory
CONTAINER_NAME="vnoj_mysql"
DATE=$(date +%F_%H-%M-%S)
BACKUP_NAME="mariadb_backup_$DATE.sql"
REMOTE_BACKUP_DIR="Onedrive_MariaDB:/OJ_Backup"  # OneDrive backup folder

# Create backup
docker exec $CONTAINER_NAME /usr/bin/mysqldump -u root --password='root' --all-databases > $BACKUP_DIR/$BACKUP_NAME

# Compress the backup file
gzip $BACKUP_DIR/$BACKUP_NAME

# Upload to OneDrive using rclone
rclone copy $BACKUP_DIR/$BACKUP_NAME.gz $REMOTE_BACKUP_DIR

# Check if upload was successful
if [ $? -eq 0 ]; then
    # Remove the local backup after successful upload
    rm $BACKUP_DIR/$BACKUP_NAME.gz
    echo "Backup uploaded and local file removed."
else
    echo "Backup upload failed, local file retained."
fi

# Optionally, remove old backups from OneDrive (keep last 7 backups on OneDrive)
rclone delete $REMOTE_BACKUP_DIR --min-age 7d


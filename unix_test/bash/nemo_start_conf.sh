#!/bin/bash
# mount to server
mount -t nfs -o nolock -o tcp -o rsize=32768,wsize=32768 192.168.5.11:/workspace  /mnt
cd /mnt/company_work/deepglint/entrance_guard
/mnt/company_work/deepglint/entrance_guar/bulid/nemo_face_cap /media/custum_ex/set.json


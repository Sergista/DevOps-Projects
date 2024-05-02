FROM ubuntu:22.04

WORKDIR build

COPY main.c .

RUN  apt update -y && \
apt install -y nginx  && apt-get install libfcgi-dev -y && apt-get -y install gcc && apt-get -y install spawn-fcgi && apt install -y curl && \
useradd -r nginx; \
chmod u-s /usr/bin/umount; \
chmod u-s /usr/bin/chsh; \
chmod u-s /usr/bin/su; \
chmod u-s /usr/bin/gpasswd; \
chmod u-s /usr/bin/passwd; \
chmod u-s /usr/bin/mount; \
chmod u-s /usr/bin/newgrp; \
chmod u-s /usr/bin/chfn; \
chmod g-s /usr/bin/expiry \
chmod g-s /usr/sbin/pam_extrausers_chkpwd \
chmod g-s /usr/sbin/unix_chkpwd; \
chmod g-s /usr/bin/wall; \
chmod g-s /usr/bin/chage; \
rm -rf /var/lib/apt/lists;

COPY nginx/nginx.conf /etc/nginx/nginx.conf

HEALTHCHECK   --interval=5m --timeout=3s \  
CMD curl -f http://localhost/ || exit 1

USER nginx

ENTRYPOINT gcc -o main main.c -lfcgi && spawn-fcgi -p 8080 main && service nginx start  && curl localhost:81
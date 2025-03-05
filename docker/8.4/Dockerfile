FROM composer:latest as composer
FROM php:8.4-fpm

ADD ./extra.ini /usr/local/etc/php/conf.d/

# User/Group globals
ENV MY_USER="phalcon" \
	MY_GROUP="phalcon" \
	MY_UID="1000" \
	MY_GID="1000" \
	PHP_VERSION="8.3" \
	LANG=en_US.UTF-8 \
    LANGUAGE=en_US.UTF-8 \
    LC_ALL=en_US.UTF-8

# User and Group
RUN set -eux && \
	groupadd -g ${MY_GID} -r ${MY_GROUP} && \
	useradd -u ${MY_UID} -m -s /bin/bash -g ${MY_GROUP} ${MY_USER}

# Update
RUN apt update -y && \
    apt install -y \
        apt-utils \
        git \
        libzip-dev \
        locales \
        nano \
        sudo \
        wget \
        zip \
        zlib1g

# PECL Packages
RUN pecl install xdebug \
      zephir_parser

# Install PHP extensions
RUN docker-php-ext-install \
        zip

# Install PHP extensions
RUN docker-php-ext-enable \
        xdebug \
        zephir_parser

# Composer
COPY --from=composer /usr/bin/composer /usr/local/bin/composer
# Bash script with helper aliases
COPY ./.bashrc /root/.bashrc
COPY ./.bashrc /home/phalcon/.bashrc

CMD ["php-fpm"]

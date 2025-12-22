ARG PHP_VERSION=8.4

FROM php:${PHP_VERSION}-fpm AS base

# This part installs the required php extensions to compile phalcon.
# Additional extensions that are mostly used are installed here too.

ARG PHP_VERSION=8.4
ARG UID=1000
ARG GID=1000
ARG USER=phalcon
ARG GROUP=phalcon

RUN set -eux \
# Add user and group \
    && groupadd -g "${GID}" "${GROUP}" \
    && useradd -l -m -u "${UID}" -g "${GID}" "${USER}" \
    && usermod -s /bin/bash "${USER}" \
    && mkdir /app \
    && chown "${USER}":"${GROUP}" /app \
    && chmod 0770 /app \
# Install needed packages \
    && apt update -y \
    && apt install -yq --no-install-recommends \
        apt-utils \
        gettext \
        git \
        libzip-dev \
        locales \
        nano \
        sudo \
        unzip \
        wget \
        zip \
    && sed -i -e 's/# de_DE.UTF-8 UTF-8/de_DE.UTF-8 UTF-8/' /etc/locale.gen \
    && sed -i -e 's/# el_GR.UTF-8 UTF-8/el_GR.UTF-8 UTF-8/' /etc/locale.gen \
    && sed -i -e 's/# en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen \
    && sed -i -e 's/# es_ES.UTF-8 UTF-8/es_ES.UTF-8 UTF-8/' /etc/locale.gen \
    && sed -i -e 's/# ru_RU.UTF-8 UTF-8/ru_RU.UTF-8 UTF-8/' /etc/locale.gen \
    && dpkg-reconfigure --frontend=noninteractive locales \
    && update-locale LANG=en_US.UTF-8 \
# Install base extensions \
    && pecl install xdebug \
      zephir_parser \
# Install PHP extensions \
    && docker-php-ext-install \
        zip \
# Install PHP extensions \
    && docker-php-ext-enable \
        xdebug \
        zephir_parser \
# Cleanup \
    && apt-get autoremove --purge -y \
    && apt-get autoclean -y \
    && apt-get clean -y \
    && rm -rf /tmp/* /var/tmp/* \
    && find /var/cache/apt/archives /var/lib/apt/lists -not -name lock -type f -delete \
    && find /var/cache -type f -delete \
    && find /var/log -type f -delete

# hadolint ignore=DL3022
COPY --from=composer/composer:2 --chown=${USER}:${GROUP} --chmod=0770 /usr/bin/composer /usr/bin/composer
COPY ./docker/extra.ini /usr/local/etc/php/conf.d/
COPY ./docker/.bashrc /root/.bashrc

# User/Group globals
ENV LANG=en_US.UTF-8 \
    LANGUAGE=en_US.UTF-8 \
    LC_ALL=en_US.UTF-8

SHELL [ "/bin/bash", "--rcfile", "/root/.bashrc", "-o", "pipefail", "-c" ]

WORKDIR /app

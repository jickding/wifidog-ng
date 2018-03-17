/*
 * Copyright (C) 2017 Jianhui Zhao <jianhuizhao329@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
 * USA
 */

#ifndef _CONFIG_H_
#define _CONFIG_H_

struct auth_server {
    int port;
    const char *host;
    const char *path;
    const char *login_path;
    const char *portal_path;
    const char *msg_path;
    const char *ping_path;
    const char *auth_path;
};

struct popular_server {
    char *hostname;
    struct popular_server *next;
};

struct whitelist_domain {
    char *domain;
    struct whitelist_domain *next;
};

struct config {
    const char *gw_interface;
    const char *gw_address;
    const char *gw_id;
    const char *ssid;
    int gw_port;
    int gw_ssl_port;
    int checkinterval;
    int clienttimeout;
    int temppass_time;

    struct auth_server authserver;
    struct popular_server *popular_servers;
    struct whitelist_domain *whitelist_domains;

    const char *login_url;
    const char *auth_url;
    const char *portal_url;
    const char *ping_url;
    const char *msg_url;
};

int parse_config();

struct config *get_config();

#endif

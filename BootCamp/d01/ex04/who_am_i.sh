#!/bin/sh
ldapsearch -x -LLL uid=$(whoami) | grep dn: | cut -c 5-

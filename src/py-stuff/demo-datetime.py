#!/usr/bin/env python

import datetime

print('Timestamp: {:%Y-%m-%d %H:%M:%S}'.format(datetime.datetime.now()))
print('Timestamp: {:%Y-%b-%d %H:%M:%S}'.format(datetime.datetime.now()))
print('Date now: %s' % datetime.datetime.now())
print('Date today: %s' % datetime.date.today())

today = datetime.date.today()
print("Today's date is {:%b, %d %Y}".format(today))

schedule = '{:%b, %d %Y}'.format(today) + ' - 6 PM to 10 PM Pacific'
schedule2 = '{:%B, %d %Y}'.format(today) + ' - 1 PM to 6 PM Central'
print('Maintenance: %s' % schedule)
print('Maintenance: %s' % schedule2)


print('----------------')

import time
print(time.strftime('%a %H:%M:%S'))

# Output:

# Timestamp: 2018-10-30 23:36:12
# Timestamp: 2018-Oct-30 23:36:12
# Date now: 2018-10-30 23:36:12.805600
# Date today: 2018-10-30
# Today's date is Oct, 30 2018
# Maintenance: Oct, 30 2018 - 6 PM to 10 PM Pacific
# Maintenance: October, 30 2018 - 1 PM to 6 PM Central
# ----------------
# Tue 23:36:12

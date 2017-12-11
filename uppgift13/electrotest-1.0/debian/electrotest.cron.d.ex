#
# Regular cron jobs for the electrotest package
#
0 4	* * *	root	[ -x /usr/bin/electrotest_maintenance ] && /usr/bin/electrotest_maintenance

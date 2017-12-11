#
# Regular cron jobs for the electrolib package
#
0 4	* * *	root	[ -x /usr/bin/electrolib_maintenance ] && /usr/bin/electrolib_maintenance

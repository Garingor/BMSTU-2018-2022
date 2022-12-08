bind = "127.0.0.1:8000"                   # Don't use port 80 becaue nginx occupied it already.
errorlog = '/Users/egor/Documents/GitHub/BMSTU_WEB_7_sem_2021/ProjectDjangoReact/logs/gunicorn-error.log'  # Make sure you have the log folder create
accesslog = '/Users/egor/Documents/GitHub/BMSTU_WEB_7_sem_2021/ProjectDjangoReact/logs/gunicorn-access.log'
loglevel = 'debug'
workers = 6     # the number of recommended workers is '2 * number of CPUs + 1'
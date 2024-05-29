######################################################################
# Ninja Parkour pro file
######################################################################

TEMPLATE = subdirs
SUBDIRS += app \
           tests

tests.depends = app

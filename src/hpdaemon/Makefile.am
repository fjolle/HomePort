#Copyright 2011 Aalborg University. All rights reserved.
#
#Redistribution and use in source and binary forms, with or without modification, are
#permitted provided that the following conditions are met:
#
#   1. Redistributions of source code must retain the above copyright notice, this list of
#      conditions and the following disclaimer.
#
#   2. Redistributions in binary form must reproduce the above copyright notice, this list
#      of conditions and the following disclaimer in the documentation and/or other materials
#      provided with the distribution.
#
#THIS SOFTWARE IS PROVIDED BY Aalborg University ''AS IS'' AND ANY EXPRESS OR IMPLIED
#WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
#FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL Aalborg University OR
#CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
#CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
#SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
#ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
#NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
#ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#The views and conclusions contained in the software and documentation are those of the
#authors and should not be interpreted as representing official policies, either expressed

AM_CPPFLAGS = \
	-I$(top_srcdir)/src/include\
	-I$(top_srcdir)/src/hpdaemon\
	$(LIBMICROHTTPD_CFLAGS)\
	$(LIBCONFIG_CFLAGS)\
	$(MINIXML_CFLAGS)

lib_LTLIBRARIES = \
  libhpd.la

libhpd_la_SOURCES = hpd_configure.c\
		    homeport.c\
		    hpd_services.c\
		    utlist.h\
		    hpd_web_server_interface.h hpd_web_server_interface.c\
		    hpd_server_sent_events.c hpd_server_sent_events.h\
		    hpd_device_configuration.c hpd_device_configuration.h\
		    hpd_log.c hpd_log.h\
		    hpd_xml.c hpd_xml.h\
		    hpd_events.c hpd_events.h\
		    hpd_web_server_core.c hpd_web_server_core.h

libhpd_la_LDFLAGS = $(HPD_LIB_LDFLAGS) 

libhpd_la_CFLAGS = -lconfig -luuid

libhpd_la_LIBADD = $(LIBMICROHTTPD_LIBS) $(LIBCONFIG_LIBS) $(MINIXML_LIBS)

if !DISABLE_AVAHI
libhpd_la_SOURCES += hpd_avahi_publish.c hpd_avahi_publish.h
if ENABLE_AVAHI_CLIENT
libhpd_la_SOURCES += hpd_avahi_publish_client.c hpd_avahi_publish_client.h
else
libhpd_la_SOURCES += hpd_avahi_publish_core.c hpd_avahi_publish_core.h
endif
endif


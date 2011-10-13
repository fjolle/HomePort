/*Copyright 2011 Aalborg University. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are
permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice, this list of
      conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright notice, this list
      of conditions and the following disclaimer in the documentation and/or other materials
      provided with the distribution.

THIS SOFTWARE IS PROVIDED BY Aalborg University ''AS IS'' AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL Aalborg University OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those of the
authors and should not be interpreted as representing official policies, either expressed*/

#ifndef HOMEPORT_H
#define HOMEPORT_H

/** @mainpage The HomePort Project
 *
 * @authors Several
 *
 * @section intro Introduction
 *
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdarg.h>

#include "services.h"
#include "hpd_configure.h"

enum HPD_FLAG
{
	HPD_NO_FLAG = 0,

	HPD_USE_OPTION = 1,

	HPD_USE_CFG_FILE = 2,

	HPD_USE_DEFAULT = 4
};

enum HPD_OPTION
{
	/** No more options / last option
	*/
	HPD_OPTION_END = 0,

	HPD_OPTION_HTTP = 1,

	HPD_OPTION_HTTPS = 2,

	HPD_OPTION_LOG = 3,

	HPD_OPTION_CFG_PATH = 4

};

int HPD_start( unsigned int option, char *_hostname, ... );
int HPD_stop();
int HPD_register_service(Service *_service);
int HPD_unregister_service(Service *_service);
int HPD_register_device_services(Device *_device);
int HPD_unregister_device_services(Device *_device);
int HPD_send_event_of_value_change (Service *service, char *_updated_value);

Service* HPD_get_service( char *_device_type, char *_device_ID, char *_service_type, char *_service_ID );
Device* HPD_get_device(char *_device_type, char *_device_ID);

#endif
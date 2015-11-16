#!/usr/bin/env node

var rapp = require("./RAPPNao.js");
var services = new rapp.RAPPNao();

function print_in_bold_and_red(text)
{
    console.log("\033[1m\033[31m" + text + "\033[0m");
}

function handler_1(result)
{ 
    print_in_bold_and_red("Result from rosapi_get_time call:");
	console.log("time.secs = " + result.time.secs);
}

services.rosapi_get_time(handler_1);

function handler_2(result)
{ 
    print_in_bold_and_red("Result from rosapi_service_host call:");
    console.log("host = " + result.host);
}

services.rosapi_service_host("/rosapi/get_time", handler_2);

function handler_say(result)
{ 
    print_in_bold_and_red("Result from rapp_say call:");
    console.log("response = " + result.response);
    process.exit();
}

function handler_moveVel(result)
{ 
    print_in_bold_and_red("Result from rapp_moveVel call:");
    console.log("response = " + result.response);
    process.exit();
}

services.rapp_say("Bonjour!", "English", handler_say);

services.rapp_moveVel(0.05, 0, 0, handler_moveVel);


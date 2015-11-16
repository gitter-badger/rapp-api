#!/usr/bin/env node

function RAPPNao()
{
    this.rosbridge_url = "ws://localhost:9090";
}

RAPPNao.prototype =
{
	// Examples of wrappers for ROS standard services.
	// ROSbridge server must be running (port: 9090). 

	// rosapi/get_time (no arguments)
	rosapi_get_time: function(callback)
	{
		var rapp = this;
		//var WebSocket = require("ws");
		var ws = new WebSocket(rapp.rosbridge_url);
		ws.onopen = function ()
		{
			var msg =
			{
				op: "call_service",
				service: "/rosapi/get_time"
			};
			ws.send(JSON.stringify(msg));
        };
        ws.onmessage = function (event)
        {
        	var eventValue = JSON.parse(event.data);
        	if (eventValue.op == "service_response")
        	{
            	callback(eventValue.values);
            }
            ws.close();
            ws = undefined;
        };
    },
    // rosapi/service_host
	rosapi_service_host: function(service_name, callback)
	{
		var rapp = this;
		//var WebSocket = require("ws");
		var ws = new WebSocket(rapp.rosbridge_url);
		ws.onopen = function ()
		{
			var msg =
			{
				op: "call_service",
				service: "/rosapi/service_host",
				args: { service: service_name }
			};
			ws.send(JSON.stringify(msg));
        };
        ws.onmessage = function (event)
        {
        	var eventValue = JSON.parse(event.data);
        	if (eventValue.op == "service_response")
        	{
            	callback(eventValue.values);
            }
            ws.close();
            ws = undefined;
        };
    },

    // /rapp_say
	rapp_say: function(request, language, callback)
	{
		var rapp = this;
		//var WebSocket = require("ws");
		var ws = new WebSocket(rapp.rosbridge_url);
		ws.onopen = function ()
		{
			var msg =
			{
				op: "call_service",
				service: "/rapp_say",
				args: { request: request,
					    language: language }
			};
			ws.send(JSON.stringify(msg));
        };
 	    ws.onmessage = function (event)
        {
        	var eventValue = JSON.parse(event.data);
        	if (eventValue.op == "service_response")
        	{
        		callback(eventValue.values);
        	}
        	ws.close();
        	ws = undefined;
        };
    },

    // /rapp_move
	rapp_moveVel: function(velocity_x, velocity_y, velocity_theta, callback)
	{
		var rapp = this;
		var ws = new WebSocket(rapp.rosbridge_url);
		ws.onopen = function ()
		{
			var msg =
			{
				op: "call_service",
				service: "/rapp_moveVel",
				args: { velocity_x: velocity_x,
						velocity_y: velocity_y,
						velocity_theta: velocity_theta}
			};
			ws.send(JSON.stringify(msg));
        };
 	    ws.onmessage = function (event)
        {
        	var eventValue = JSON.parse(event.data);
        	if (eventValue.op == "service_response")
        	{
        		callback(eventValue.values);
        	}
        	ws.close();
        	ws = undefined;
        };
    }




}

module.exports.RAPPNao = RAPPNao;

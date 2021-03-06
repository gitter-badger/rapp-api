#!/usr/bin/env node

var RAPPCloud = require('./../../../RAPPCloud.js');
var RAPPObject = require('./../../objects/face/face.js')

/**
 * Prototype the RAPPCloud Service Method.
 * 
 * @method faceDetector
 * @brief Asynchronous Service which will request the cloud to detect faces
 * @version 1
 * @date 20-September-2015
 * @author Lazaros Penteridis <lp@ortelio.co.uk>
 */ 

/**
 * @brief Constructor
 * @param image is the input image @see rapp::object::picture
 * @param image_format is the image format
 * @param callback is the function that will receive a vector of the detected face(s) coordinates
 */
RAPPCloud.prototype.faceDetector = function ( image, callback )
{
    var cloud = this;
    var objects = new RAPPObject( );
    var _delegate=callback;
    var FormData = require('form-data');
	var fs = require('fs');
	var form = new FormData();
	var request = require('request');
	
	form.append('file_uri', fs.createReadStream(image));
	
	var r = request.post(cloud.cloud_url + '/hop/face_detection/ ', function(error, res, json){ 
		if (res.statusCode==200 && !error){
			handle_reply(json);
			}
		else if (error) {
			error_handler(error);
		}
		else if ( response.statusCode != 200 ) {
			console.log(res.statusCode);
		}
	});
	r._form = form;
	r.setHeader('Connection', 'close');

	function handle_reply( json )
    {
		var json_obj, face_temp;
		var faces = [];
		try {
			json_obj = JSON.parse(json);
			if(json_obj.error){  // Check for Errors returned by the api.rapp.cloud
				console.log('faceDetection JSON error: ' + json_obj.error);
			}
			// JSON reply is eg.: { "faces":[{"up_left_point":{"x":212.0,"y":200.0},"down_right_point":{"x":391.0,"y":379.0}}],"error":""}
			if (json_obj.faces.length){
				for (i=0; i<json_obj.faces.length; i++){
					var up_left = json_obj.faces[i].up_left_point;
					var down_right = json_obj.faces[i].down_right_point;
					faces.push(new objects.Face( up_left.x, up_left.y, down_right.x, down_right.y ));
				}
				_delegate(faces);
			}
		} catch (e) {
			console.log("faceDetector::handle_reply Error parsing: ");
			return console.error(e);
		}
	}
	
	function error_handler( error ) {
		return console.error(error);
	}
}



/// Export
module.exports = RAPPCloud.faceDetector;

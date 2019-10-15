extends Node

func _ready():
	self.log("Config files are located in " + str(OS.get_user_data_dir()))

func debug(text):
	#if Debug.enabled:
	if true:
		self.log("DEBUG: " + text)

func error(text):
	self.log("ERROR: " + text)

func warn(text):
	self.log("WARNING: " + text)

func log(text):
	print(_date_prefix() + text)

func _date_prefix():
	var dt = OS.get_datetime()
	var hour = str(dt["hour"]).pad_zeros(2)
	var minute = str(dt["minute"]).pad_zeros(2)
	var second = str(dt["second"]).pad_zeros(2)
	return "[" + hour + ":" + minute + ":" + second + "] "
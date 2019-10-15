extends Control

# Called when the node enters the scene tree for the first time.
func _ready():
	var err
	
	#Game.playing = false
	
	err = $Panel/HBoxContainer/VBox/ContinueBtn.connect("pressed", self, "game_continue")
	assert(err == OK)
	err = $Panel/HBoxContainer/VBox/NewGameBtn.connect("pressed", self, "game_new")
	assert(err == OK)
	#err = $Panel/HBoxContainer/VBox/SettingsBtn.connect("pressed", $Panels/Settings, "activate")
	#assert(err == OK)
	err = $Panel/HBoxContainer/VBox/QuitBtn.connect("pressed", self, "quit")
	assert(err == OK)
	
	$Panel/HBoxContainer/VBox/ContinueBtn.disabled = not Settings.fetch("has_played")
	
	Input.set_mouse_mode(Input.MOUSE_MODE_VISIBLE)
	Game.focus_first_control(self)

func game_continue():
	hide()
	Game.load_level(Game.get_current_level())

func game_new():
	Settings.store("has_played", true)
	Settings.store("current_level", Game.FIRST_LEVEL)
	game_continue()

# TODO: Add quit prompt.
func quit():
	Game.quit()
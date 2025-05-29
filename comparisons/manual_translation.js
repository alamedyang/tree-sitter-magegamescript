const fs = require('node:fs');

const file = `include!("header.mgs")

show_dialog-timewarp {
	register rtfm -> command-rtfm;
	if (flag demo-cutseen-timewarp is false) {
		fade out camera to #000000 over 1ms;
		wait 200ms;
		turn player control off;
		turn entity "%PLAYER%" south;
		show dialog {
			name "" "...."
			"Am I asleep?"
		}
		fade in camera from #000000 over 2000ms;
		show dialog {
			PLAYER alignment BL
			"Huh? Is this the village?"
			"No, this is the village of the past. But\nI still have Ring Zero...."
			"This has got to be a dream."
		}
		turn player control on;
		set flag demo-cutseen-timewarp to true;
	}
	turn hex control on;
}

show_dialog-bob-first-demo_map {
	if (flag demo-bob-backstory is false) {
		show dialog {
			SELF "Name's Bob."
			"Stone Cold Bob Austin."
			"Right, what's yours, then?"
			PLAYER "You don't know who I am? We've both lived here for years!"
			SELF "Don't know nobody. All I know is, gotta keep everyone out."
			"You know, unless their name is Bob."
			PLAYER "Bob?"
			SELF "Bob. Camel case.\nNice and plain.\nTraditional."
			"'Cause this club is Bobs-only. You know, the Bobs-Only Club."
			PLAYER "Why is it Bobs only?"
			SELF "Why?\nWhy is it Bobs only?"
			"Why, it wouldn't be the Bobs-Only Club if I just let anyone in!"
		}
		set flag demo-bob-backstory to true;
	} else if (flag demo-bob-notimplemented is true) {
		show dialog {
			SELF "So, what's your name, then?"
			PLAYER "The door doesn't work! What does it matter what my name is?"
			SELF "Not my job. My only job is to keep everyone out who's not named Bob."
		}
	} else {
		show dialog {
			SELF "So, what's your name then?"
		}
		if (entity "%PLAYER%" name is not Bob) {
			show dialog {
				PLAYER "Um.... it's not Bob."
				SELF "Sorry, can't unlock the door for ya. Bobs only."
			}
			return; // return early
		}
		show dialog {
			PLAYER "Why, what luck!\nMy name happens to be Bob!"
			SELF "Nice. Great name.\nI'll unlock the door."
		}
		walk entity Bob to geometry "%ENTITY_PATH%" over 666ms;
		turn entity Bob west;
		wait 666ms;
		turn entity Bob south;
		show dialog {
			SELF "There you go. It's open."
		}
		walk entity "%PLAYER%" to geometry predoor over 666ms;
		walk entity "%PLAYER%" to geometry door over 1333ms;
		wait 666ms;
		turn entity "%PLAYER%" east;
		show dialog {
			PLAYER "Hey, what gives?\nI still can't get in."
		}
		turn entity Bob west;
		show dialog {
			SELF "Oh, it's unlocked."
			PLAYER "Then why won't it open?"
			SELF "Oh. The door's not implemented yet."
			PLAYER "...."
			"You could've said that from the start!"
			SELF "Not my job. My only job is to keep everyone out who's not named Bob."
		}
		turn entity Bob south;
		set flag demo-bob-notimplemented to true;
	}
}

show_dialog-sheep-demo_map {
	show dialog { SELF "...." }
}
show_dialog-dsheep-demo_map {
	show dialog { SELF "...?" }
}

show_dialog-max-demo_map {
	copy face-player;
	show dialog {
		SELF "Ah, a citizen!"
		"I wondered if you could help me!"
		PLAYER "What do you need?"
		SELF "My name's Swagger! Max Swagger!"
		"I was doing a bit of reconnoissance, looking for a place where I can open my new fashion shop."
		"The board here says there's space available, but I can't seem to find the building it's talking about."
		"The only thing actually here is the Bobs-Only Club!"
		PLAYER "Well, the town isn't fully implemented yet, so... you might have to wait a few more weeks for the rest of the buildings to return."
	}
	turn player control off;
	rotate entity "%SELF%" -2;
	wait 800ms;
	rotate entity "%SELF%" 1;
	wait 800ms;
	turn player control on;
	copy face-player;
	show dialog {
		SELF "Not fully implemented?"
		PLAYER "Sorry."
		"But I can personally guarantee you can have a building all to yourself when the time comes."
		SELF "Oh! That's good news! All to myself?"
		"I'm picturing two stories... no, three!"
		"Lush woven carpets... vaulted ceilings... beautiful oak doors... hand-carved decorative moulding...."
		PLAYER "Um, well.... You'll definitely get a building."
		SELF "Excellent! Then I shall return when the time comes!"
		"Until that glorious day, farewell!"
	}
	walk entity "%SELF%" along geometry "%ENTITY_PATH%" over 9000ms;
	teleport entity "%SELF%" to geometry hiding;
}

show_dialog-timmy-demo_map {
	copy interrupt-walk;
	show dialog {
		SELF "I'm practicing for my triathlon!"
		"Running is my weakest event, so I'm working hard to improve my time!"
		PLAYER "Don't you need legs to run?"
		SELF "...?"
		"No?"
	}
	copy resume-walk;
}

show_dialog-kid-demo_map {
	copy interrupt-walk;
	show dialog {
		SELF "I'm gonna be a Blitzball when I grow up!"
	}
	copy resume-walk;
}

show_dialog-goose-demo_map {
	show dialog {
		SELF "Honk!"
	}
}

show_dialog-beatrice-demo_map {
	turn player control off;
	copy face-player;
	show dialog {
		SELF "Back when he was a young man, my husband Delmar hand-carved all the statues on the fountains around town."
		"Such a shame that this one isn't working. I wonder if something is clogging the pump."
	}
	rotate entity "%SELF%" 1;
	wait 600ms;
	rotate entity "%SELF%" -2;
	wait 600ms;
	copy face-player;
	show dialog {
		SELF "Between you and me.... I think the goose has something to do with it."
	}
	turn player control on;
	turn entity "%SELF%" south;
}

show_dialog-trekkie-demo_map {
	copy face-player;
	show dialog {
		SELF "Me heard you will soon have a birthday!"
		PLAYER "That's right! I'll be turning 16, and I'll get to be an official village mage!"
		SELF "Me hope you have happy birthday!"
		PLAYER "Thanks very much, %Trekkie%!"
	}
}

show_dialog-verthandi-demo_map {
	copy face-player;
	show dialog {
		SELF "I'm so glad the goats made up and are friends again!"
	}
	turn entity "%SELF%" south;
}

show_dialog-goat-demo_map {
	show dialog { SELF "Baaahhh!" }
}

show_dialog-cleo1-demo_map {
	show dialog {
		Cat "Meowrrow."
		Cleo "Oh, you don't say!"
		Cat "Meow!"
		Cleo "He didn't!"
	}
	set entity "%SELF%" on_interact to show_dialog-cleo2;
}

show_dialog-cleo2-demo_map {
	show dialog {
		Cat "Meowwowow."
		Cleo "That's what I've been saying this whole time!"
		Cat "Meowwrrrr!"
		Cleo "Oh, I know!"
	}
	set entity "%SELF%" on_interact to show_dialog-cleo1-demo_map;
}

show_dialog-cat-demo_map {
	show dialog {
		PLAYER "Hey there, cat!"
		Cat "...."
		Cleo "Excuse me, but we were in the middle of a conversation."
		PLAYER "Oh, sorry. Carry on."
	}
}

show_dialog-smith-demo_map {
	copy face-player;
	show dialog {
		SELF "I came here on a blacksmithing scholarship, but there's not much blacksmithing to do at the moment."
		"I think I'll stick around anyway. See what happens."
	}
}

check_if_player_is_goat_high-demo_map {
	if (entity "%PLAYER%" is inside geometry high) {
		set entity goat1 on_tick to move_goat1_to_low-demo_map;
		set entity goat2 on_tick to move_goat2_to_low-demo_map;
		goto check_if_player_is_goat_low-demo_map;
	}
}

check_if_player_is_goat_low-demo_map {
	if (entity "%PLAYER%" is inside geometry low) {
		set entity goat1 on_tick to move_goat1_to_high-demo_map;
		set entity goat2 on_tick to move_goat2_to_high-demo_map;
		goto check_if_player_is_goat_high-demo_map;
	}
}

move_goat1_to_low-demo_map {
	walk entity goat1 to geometry low1 over 600ms;
	loop entity goat1 along geometry low1 over 2000ms;
}

move_goat2_to_low-demo_map {
	walk entity goat2 to geometry low2 over 733ms;
	loop entity goat2 along geometry low2 over 2266ms;
}

move_goat1_to_high-demo_map {
	walk entity goat1 to geometry high1 over 600ms;
	loop entity goat1 along geometry high1 over 2000ms;
}

move_goat2_to_high-demo_map {
	walk entity goat2 to geometry high2 over 733ms;
	loop entity goat2 along geometry high2 over 2266ms;
}

loop_on_path_30s-demo_map {
	loop entity "%SELF%" along geometry "%ENTITY_PATH%" over 20000ms;
}

loop_on_path_10s-demo_map {
	loop entity "%SELF%" along geometry "%ENTITY_PATH%" over 6666ms;
}

loop_on_path_3s-demo_map {
	loop entity "%SELF%" along geometry "%ENTITY_PATH%" over 2000ms;
}

// Chaos fish
show_dialog-demo-end-dream-q {
	show dialog {
		SELF
		portrait goldfish
		"End this dream?"
		> "Yes (save and quit)" : goto "demo-end-dream-yes-save"
		> "Yes (quit without saving)" : goto "demo-end-dream-yes"
		> "No (continue dream)" : goto "demo-end-dream-no"
	}
}
demo-end-dream-yes {
	load map main_menu;
}
demo-end-dream-yes-save {
	save slot;
	load map main_menu;
}
demo-end-dream-no {
	set entity "%SELF%" on_interact to show_dialog-demo-end-dream-q;
}

// Unused (from original prerelease demo; did not get plugged in properly)
dialog dialog-max3-demo_map {
	PLAYER "Not much of a market for fashion here, I would've thought."
	"Best of luck, Max Swagger!"
}
`;


const replaced = file
	.replace(/include!\((.+?)\)/g, 'include $1;')
	.replace(/copy ("?)([^;]+)(\1);?/g, 'copy!("$2")')
	.replace(/goto( script)? ("?)([^;]+)(\2)/g, 'goto "$3"')
	.replace(/(entity|geometry|map) ("?)([-_a-zA-Z0-9]+)(\2)/g, '$1 "$3"')
	.replace(/(^|\n)([-_A-Z0-9a-z]+?) {\n/g,'$1"$2" {\n')
	.replace(/(^|\n)dialog ([-_A-Z0-9a-z]+?) {\n/g,'$1dialog "$2" {\n')
	.replace(
		/register +(.+?) +-> +([-A-Z0-9a-z]+)/g,
		'command "$1" = "$2"'
	)
	.replace(
		/show dialog ([^}]+)}/g,
		'show dialog $1};'
	)
	.replace(
		/> (.+) : goto( script)? ([^\n]+)/g,
		'> $1 = $3'
	)
	.replace(/flag ([-A-Z0-9a-z]+) is true/g, '"$1"')
	.replace(/flag ([-A-Z0-9a-z]+) is false/g, '!"$1"')
	.replace(/set flag ([-A-Z0-9a-z]+) to (true|false)/g, '"$1" = $2')
	.replace(
		/turn player control (on|off)/g,
		'player_control = $1'
	)
	.replace(
		/turn hex control (on|off)/g,
		'hex_control = $1'
	)
	.replace(
		/fade (out|in) camera (to|from) (.+) over (.+)/g,
		'camera fade $1 -> $3 over $4'
	)
	.replace(
		/turn entity (".+") ([a-z]+)/g,
		'entity $1 direction = $2'
	)
	.replace(
		/entity (.+) (name|type|path|on_interact|on_tick|on_look) is not ("?)([^)]+)(\3)/g,
		'entity $1 $2 != "$4"'
	)
	.replace(
		/entity (.+) (name|type|path|on_interact|on_tick|on_look) is ("?)([^)]+)(\3)/g,
		'entity $1 $2 == "$4"'
	)
	.replace(
		/entity (.+) ([a-z]+) is not ([-A-Z0-9a-z]+)/g,
		'entity $1 $2 != $3'
	)
	.replace(
		/entity (.+) ([a-z]+) is ([-A-Z0-9a-z]+)/g,
		'entity $1 $2 == $3'
	)
	.replace(
		/walk entity (.+) to geometry (.+) over ([0-9ms]+)/g,
		'entity $1 position -> geometry $2 origin over $3'
	)
	.replace(
		/turn entity (.+) ([a-z]+)/g,
		'entity $1 direction = $2'
	)
	.replace(
		/rotate entity (.+) -([0-9]+)/g,
		'entity $1 direction -= $2'
	)
	.replace(
		/rotate entity (.+) ([0-9]+)/g,
		'entity $1 direction += $2'
	)
	.replace(
		/walk entity (.+) along geometry ([^\)]+) over ([0-9ms]+)/g,
		'entity $1 position -> geometry $2 length over $3'
	)
	.replace(
		/teleport entity (.+) to geometry ([^\)]+)/g,
		'entity $1 position = geometry $2'
	)
	.replace(
		/set entity (.+) (name|type|path|on_interact|on_tick|on_look) to ("?)([^;]+)(\3)/g,
		'entity $1 $2 = "$4"'
	)
	.replace(
		/entity (.+) is inside geometry ([^\)]+)/g,
		'entity $1 intersects geometry $2'
	)
	.replace(
		/loop entity (.+?) along geometry ([^\)]+?) over ([0-9ms]+)/g,
		'entity $1 position -> geometry $2 length over $3 forever'
	)
	// LAST
	.replace(/entity "%PLAYER%"/g, 'player')
	.replace(/entity "%SELF%"/g, 'self')


	fs.writeFileSync('./comparisons/manual_export.mgs', replaced);

	console.log(replaced);
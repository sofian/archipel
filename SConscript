# Don't change these lines
Import(['CONFIG', 'platform', 'mode'])
for (k, v) in CONFIG.items():
  vars()[k] = v
# ------------------------

# Begin: editable zone #######################################

from os import path

# Program-specific settings
#TARGET = "TestSoundDNA"
#TARGET = "Archipel1"
TARGET = "Archipel3"
#TARGET = "TestSampleScrub2"

#ARDUINO_EXTRA_LIBRARIES = "Streaming,SoftPWM"

ARDUINO_BOARD = 'mega'

# Edit these to match your system configuration.
ARDUINO_SKETCHBOOK_HOME = "/home/tats/Documents/Arduino/"

QUALIA_DIR = "/home/tats/Documents/workspace/qualia/"

# Extra options
INCPATH = ":".join([path.join(QUALIA_DIR, "src")])

LIBPATH = ":".join([path.join(QUALIA_DIR, "build/arduino/qualia")])
LIBS    = ["qualia"]

platform="arduino"

# End:   editable zone #######################################

# Don't change these lines
for (k, v) in CONFIG.items():
  CONFIG[k] = vars()[k]
CONFIG['platform'] = platform
CONFIG['mode'] = mode
Return('CONFIG')
# ------------------------

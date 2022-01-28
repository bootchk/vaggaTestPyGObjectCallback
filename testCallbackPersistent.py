# Test GObject callbacks

import gi
gi.require_version('TestCallback', '1.0')
from gi.repository import TestCallback

# TestCallback is a namespace i.e. a library you can call.

# Python functions which we register as callbacks to be called  back from the library
#
# Note that the guest (C library) signature is different.
# These use the native (host Python) signature.
# PyGObject marshals args from the guest into the native
#

def callbackWData(drawables, runData):
  print("Called back")
  print("Length of array:", str(len(drawables)) )
  print("Array[0], a pointer to an int:", str(drawables[0]))
  print("Array[1], a pointer to an int:", str(drawables[1]))
  print("runData:", str(runData))







# When registered as a persistent callback, you can ask for a callback many times
#
# int passed as runData will be returned in the callback
#
# Here, we omit the destroyFunction, and the binding provides NULL?
TestCallback.registerPersistentCallbackWData(callbackWData, 1)
TestCallback.callCallbackWData()
# Invoke a second time
TestCallback.callCallbackWData()
# expect output
# "Called back" "Length of array: 2" "runData: 1"

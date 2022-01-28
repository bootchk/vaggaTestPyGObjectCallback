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
# We can register a host native signature to receive different guest args
# as long as both sets of guest args marshall into the same native type.
# Here, both host args (int, array) and GList* marshal into a native Python list

def callback(self, drawables):
  print("Called back")
  print("Length of array:", str(len(drawables)) )
  print("Array[0], a pointer to an int:", str(drawables[0]))
  print("Array[1], a pointer to an int:", str(drawables[1]))





# the test:
TestCallback.registerCallback(callback)
TestCallback.callCallback()
# expect output "Called back" "Length of array: 2"

# If you call callback a second time
# expect a seg fault
# TestCallback.callCallback()

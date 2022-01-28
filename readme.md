
A minimal working example, or demo.
Of a GObject introspected C library called from Python.
With emphasis on callbacks from the library, passing arrays.

GObject Introspection (GI) is used mainly by Gnome apps, and examples are hard to find.

Demonstrates:
   - meson build
   - annotation.

Also includes a vagga script.  
You can build the project in a vagga container.
That is more or less documentation of minimal development tools.
The vagga script demonstrates how to build PyGObject.

Is a test case for one feature (callbacks) of GObject introspection.
More specifically, callbacks that pass an array of things.
When called back, PyGObject should marshal the array into a native Python list.
The motivation is a seeming bug in GIMP,
where this case does not seem to be handled correctly by PyGObject?

Most introspection and marshalling is in the forward direction, from the host (Python) to the guest (C).
In the case of a callback, the direction is reverse.
The guest (C) is calling the host (Python.)
The binding machinery interposes/shims a marshalling function between the C call to the callback
and the Python callback?

The Python test programs first imports gi and the introspected TestCallback library.
Then the Python test programs call the library to register a Python function as a callback.
Then the Python test programs call the library asking the library to call back.
The library calls back, passing an array.
The called back Python function should receive a native Python list.

There are different test cases for the scope (life) of the callback.


Notes of things I learned:

The "nsversion" of a typelib is only two digits.  "0.0.1" doesn't work.

The "symbol_prefix" string must be used as prefix of all names of functions in the introspected library.
That is not obvious, it is easy to think it is a coding convention.
But GI actually depends on it.
Said prefix need no be separated by an underbar, but usually is, and the underbar between the prefix and the rest is ignored?
Also, the "symbol prefix" must be lower case, even though the namespace name is capitalized.
For example, the namespace name is TestCallback, but each function in the library starts with "testcallback_"

The include file (.h) must be present and include the exposed functions of the library.
If not, the library couldn't be compiled into any program.
But also, introspection seems to only introspect functions declared in the header,
even though the annotations are in the .c file?

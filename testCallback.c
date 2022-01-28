
/*
A library called from Python, and calling back to Python
*/

// Include Glib before the header for this file
#include <glib-object.h>

#include "testCallback.h"




/*
Storage for  callbacks.
Library is not shareable since has static variables?
*/
static TestCallbackCallback           theCallback = 0;



/*
Static data to be passed in callback call.
Usually such data would be dynamic.
For example, in GIMP, it is certain choices the user has made in a GUI app,
e.g. the image and drawable.
*/
gint a = 1;
gint b = 2;

gint* intPointerArray[] = { &a, &b };


/**
 * testcallback_registerCallback:
 * @aCallback:  (scope async):       the callback, to be called later, asynchronously, but only once
 *
 * Registers a callback which the library will call when Python calls callCallback()
 **/
void
testcallback_registerCallback ( TestCallbackCallback aCallback )
{
  g_printerr("Registering callback.\n");
  theCallback = aCallback;
}





#ifdef NOT_WORKING
/**
 * testcallback_registerPersistentCallbackWListData:
 * @aCallback:                                       the callback, to be called later
 * @runData:        (closure aCallback):             user data registered and fed back by @aCallback
 * @runDataDestroy: (destroy aCallback) (nullable):  free function for @runData, or %NULL.
 *
 * Registers a callback which the library will call when Python calls callCallbackWData()
 **/
void
testcallback_registerPersistentCallbackWListData
  ( TestCallbackCallbackWListData aCallback,
    gpointer                      runData,
    GDestroyNotify                runDataDestroy
  )
{
  g_printerr("Registering persistent callback with list.\n");
  theCallbackWListData = aCallback;
  g_printerr("Registering runData %p.\n", runData);
  theRunData = runData;
}

/**
 * testcallback_registerfoo:
 * @aCallback:                                       the callback, to be called later
 * @runData:        (closure aCallback):             user data registered and fed back by @aCallback
 * @runDataDestroy: (destroy aCallback) (nullable):  free function for @runData, or %NULL.
 *
 * Registers a callback which the library will call when Python calls callCallbackWData()
 *
 **/
void
testcallback_registerfoo
  ( TestCallbackCallbackWListData aCallback,
    gpointer                      runData,
    GDestroyNotify                runDataDestroy
  )
{
  g_printerr("Registering persistent callback with list.\n");
  theCallbackWListData = aCallback;
  g_printerr("Registering runData %p.\n", runData);
  theRunData = runData;
}


#endif


/*
Functions called from Python to ask the library to callback into Python.
*/


/**
 * testcallback_callCallback:
 *
 * From the guest language (C) call the Python callback previously registered
 **/
void
testcallback_callCallback( )
{
  if (!theCallback)
    g_printerr("No callback registered.\n");
  else {
    g_printerr("Invoking callback.\n");
    // invoke the callback with dummy values
    theCallback(2, intPointerArray);
  }
}


#ifdef NOT_WORKING
/**
 * testcallback_callCallbackWListData:
 *
 * From the guest language (C) call the Python callback previously registered
 * On this C side, pass list and data.
 **/
 void
testcallback_callCallbackWListData( )
{
  if (!theCallbackWData)
    g_printerr("No callback registered.\n");
  else {
    // invoke the callback with dummy values and the retained runData

    // Use a GList
    g_printerr("Invoking persistent callback with dynamic GList.\n");
    GList* aGlist = NULL;
    aGlist = g_list_append(aGlist, "foo");
    aGlist = g_list_append(aGlist, "bar");
    // WAS aGList, *aGlist
    theCallbackWListData((gpointer) aGlist, theRunData);
  }
}

#endif

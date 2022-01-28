

// Include Glib before the header for this file
#include <glib-object.h>

#include "testCallbackPersistent.h"

#ifdef OLD
// * @run_data: (closure run_func): user data passed to @run_func.
// * @run_data_destroy: (destroy run_func) (nullable): free function for @run_data, or %NULL.
#endif

static TestCallbackCallbackWData      theCallbackWData = 0;
// static TestCallbackCallbackWListData  theCallbackWListData = 0;

/* Registered data to pass at callback time. */
static gpointer theRunData = 0;


/*
(scope notified)
* means the callback persists and can be called back many times.
* The registrar can destroy the registered, i.e. retained, aCallback AND runData when ????
* The registree (Python and PyGObject) will retain resources
* necessary to marshal callbacks to the Python function
* until receiving the signal runDataDestroy.
* Why would the registrar (the C library) want to arbitraily destroy the callback machinery???
*/

/**
 * testcallback_registerPersistentCallbackWData:
 * @aCallback:                     the callback, to be called later // (scope notified):
 * @runData:        (closure aCallback):             user data registered and fed back by @aCallback
 * @runDataDestroy: (destroy aCallback) (nullable):  free function for @runData, or %NULL.
 *
 * Registers a callback which the library will call when Python calls callCallbackWData()
 **/
void
testcallback_registerPersistentCallbackWData
  ( TestCallbackCallbackWData aCallback,
    gpointer                  runData,
    GDestroyNotify            runDataDestroy
  )
{
  g_printerr("Registering persistent callback.\n");
  theCallbackWData = aCallback;
  g_printerr("Registering runData %p.\n", runData);
  theRunData = runData;
}





/**
 * testcallback_callCallbackWData:
 *
 * From the guest language (C) call the Python callback previously registered
 **/
 void
testcallback_callCallbackWData( )
{
  if (!theCallbackWData)
    g_printerr("No callback registered.\n");
  else {
    // invoke the callback with dummy values and the retained runData

    // Use static data
    //g_printerr("Invoking persistent callback with static data.\n");
    //theCallbackWData(2, intPointerArray, theRunData);

    // Use dynamic data
    g_printerr("Invoking persistent callback with dynamic data.\n");
    gpointer* anArray = (void**) g_new (GObject *, 2);
    // The array is pointers, uninitialized
    theCallbackWData(2, (int**) anArray, theRunData);
  }
}

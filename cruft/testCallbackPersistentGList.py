'''
Not working:  callback passes GList



print(dir(TestCallback))

# Register a callback where the guest sends a list.
# Note this is a different registration, but the callback function on Python side is the same
# ??? not working
#TestCallback.registerPersistentCallbackWListData(callbackWData, None)
TestCallback.registerfoo(callbackWData, None)

# Ask for a callback where the original was a C GList
# Note the same python function is called back
TestCallback.callCallbackWListData()
'''

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

#ifdef NOT_WORKING
/*
Register as a persistent callback, can call back many times.

Here, we register a  callback of another type,
which sends a GList
*/
void testcallback_registerPersistentCallbackWListData
  ( TestCallbackCallbackWListData aCallback,
    gpointer                      runData,
    GDestroyNotify                runDataDestroy
  );

void testcallback_registerfoo
  ( TestCallbackCallbackWListData aCallback,
    gpointer                      runData,
    GDestroyNotify                runDataDestroy
  );
#endif

/*
Fails to introspect:
GList *
GList
*/
/**
 * TestCallbackCallbackWListData:
 * @drawables: (transfer container):       a GList
 * @runData:   (closure):                  registered data, passed back at callback time
 *
 * The callback is called back from the guest when the host calls callCallbackWData()

 * See annotation.
 * It can be called back many times.
 **/
 typedef void (* TestCallbackCallbackWListData)
                                       (GList *  drawables,
                                        gpointer  runData
                                        );







# We can register a host native signature to receive different guest args
# as long as both sets of guest args marshall into the same native type.
# Here, both host args (int, array) and GList* marshal into a native Python list

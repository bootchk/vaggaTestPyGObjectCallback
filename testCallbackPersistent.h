
#include <glib-object.h>


/*
runData is called "user_data" in GI annotation docs.
It is passed by the registree, stored by the registrar,
and the registrar returns it to the registree at callback time.
*/

/**
 * TestCallbackCallbackWData:
 * @array_length:                           the length of the array
 * @drawables: (array length=array_length): the input array
 * @runData:   (closure):                   registered data, passed back at callback time
 *
 * The callback is called back from the guest when the host calls callCallbackWData()
 **/
typedef void (* TestCallbackCallbackWData)
                                      (gint     array_length,
                                       gint   **drawables,
                                       gpointer runData
                                       );



/*
Register as a persistent callback, can call back many times.

In GIMP, this is Gimp.ImageProcedure.new()
Which is declared with a destroy func arg,
but the Python call never passes it?
*/
void testcallback_registerPersistentCallbackWData
  ( TestCallbackCallbackWData aCallback,
    gpointer                  runData,
    GDestroyNotify            runDataDestroy
  );


/*
Make guest library call the callback into the host.
*/
void testcallback_callCallbackWData ( void );

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

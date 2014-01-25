

#include "private.h"


VOID
kJtagEvtIoStop(
    __in WDFQUEUE         Queue,
    __in WDFREQUEST       Request,
    __in ULONG            ActionFlags
    )
/*++

Routine Description:

    This callback is invoked on every inflight request when the device
    is suspended or removed. Since our inflight read and write requests
    are actually pending in the target device, we will just acknowledge
    its presence. Until we acknowledge, complete, or requeue the requests
    framework will wait before allowing the device suspend or remove to
    proceeed. When the underlying USB stack gets the request to suspend or
    remove, it will fail all the pending requests.

Arguments:

Return Value:
    None

--*/
{
    PREQUEST_CONTEXT reqContext;

    UNREFERENCED_PARAMETER(Queue);


    reqContext=GetRequestContext(Request);

    if (ActionFlags & WdfRequestStopActionSuspend ) {
        WdfRequestStopAcknowledge(Request, FALSE); // Don't requeue
    } else if(ActionFlags & WdfRequestStopActionPurge) {
        WdfRequestCancelSentRequest(Request);
    }
    return;
}

VOID
kJtagEvtIoResume(
    IN WDFQUEUE   Queue,
    IN WDFREQUEST Request
    )
/*++

Routine Description:

     This callback is invoked for every request pending in the driver - in-flight
     request - to notify that the hardware is ready for contiuing the processing
     of the request.

Arguments:

    Queue - Queue the request currently belongs to
    Request - Request that is currently out of queue and being processed by the driver

Return Value:

    None.

--*/
{
	UNREFERENCED_PARAMETER(Queue);
	UNREFERENCED_PARAMETER(Request);
    // Leave this function here for now in case we want to add anything in the future
}

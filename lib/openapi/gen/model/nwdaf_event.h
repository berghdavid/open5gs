/*
 * nwdaf_event.h
 *
 * Describes the NWDAF Events.   Possible values are: - SLICE_LOAD_LEVEL: Indicates that the event subscribed is load level information of Network   Slice. - NETWORK_PERFORMANCE: Indicates that the event subscribed is network performance   information. - NF_LOAD: Indicates that the event subscribed is load level and status of one or several   Network Functions. - SERVICE_EXPERIENCE: Indicates that the event subscribed is service experience. - UE_MOBILITY: Indicates that the event subscribed is UE mobility information. - UE_COMMUNICATION: Indicates that the event subscribed is UE communication information. - QOS_SUSTAINABILITY: Indicates that the event subscribed is QoS sustainability. - ABNORMAL_BEHAVIOUR: Indicates that the event subscribed is abnormal behaviour. - USER_DATA_CONGESTION: Indicates that the event subscribed is user data congestion   information. - NSI_LOAD_LEVEL: Indicates that the event subscribed is load level information of Network   Slice and the optionally associated Network Slice Instance. - DN_PERFORMANCE: Indicates that the event subscribed is DN performance information. - DISPERSION: Indicates that the event subscribed is dispersion information. - RED_TRANS_EXP: Indicates that the event subscribed is redundant transmission experience. - WLAN_PERFORMANCE: Indicates that the event subscribed is WLAN performance. - SM_CONGESTION: Indicates the Session Management Congestion Control Experience information   for specific DNN and/or S-NSSAI. - PFD_DETERMINATION: Indicates that the event subscribed is the PFD Determination nformation   for known application identifier(s). - PDU_SESSION_TRAFFIC: Indicates that the event subscribed is the PDU Session traffic   information. - E2E_DATA_VOL_TRANS_TIME: Indicates that the event subscribed is of E2E data volume    transfer time. - MOVEMENT_BEHAVIOUR: Indicates that the event subscribed is the Movement Behaviour   information. - LOC_ACCURACY: Indicates that the event subscribed is of location accuracy. - RELATIVE_PROXIMITY: Indicates that the event subscribed is the Relative Proximity   information. - SIGNALLING_STORM: Indicates that the event subscribed is the Signalling Storm information. - QOS_POLICY_ASSIST: Indicates that the event subscribed is the QoS and Policy   Assistance information. 
 */

#ifndef _OpenAPI_nwdaf_event_H_
#define _OpenAPI_nwdaf_event_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_nwdaf_event_s OpenAPI_nwdaf_event_t;
typedef struct OpenAPI_nwdaf_event_s {
} OpenAPI_nwdaf_event_t;

OpenAPI_nwdaf_event_t *OpenAPI_nwdaf_event_create(
);
void OpenAPI_nwdaf_event_free(OpenAPI_nwdaf_event_t *nwdaf_event);
OpenAPI_nwdaf_event_t *OpenAPI_nwdaf_event_parseFromJSON(cJSON *nwdaf_eventJSON);
cJSON *OpenAPI_nwdaf_event_convertToJSON(OpenAPI_nwdaf_event_t *nwdaf_event);
OpenAPI_nwdaf_event_t *OpenAPI_nwdaf_event_copy(OpenAPI_nwdaf_event_t *dst, OpenAPI_nwdaf_event_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_nwdaf_event_H_ */


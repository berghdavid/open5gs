#!/bin/sh

openapi-generator-cli generate -i ./specs/19.6.0/TS29572_Nlmf_Broadcast.yaml -c spec.yaml -g c -o gen
openapi-generator-cli generate -i ./specs/19.6.0/TS29572_Nlmf_DataExposure.yaml -c spec.yaml -g c -o gen
openapi-generator-cli generate -i ./specs/19.6.0/TS29572_Nlmf_Location.yaml -c spec.yaml -g c -o gen --skip-validate-spec

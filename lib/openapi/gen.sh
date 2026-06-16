#!/bin/sh

openapi-generator-cli generate -i ./specs/19.6.0/TS29572_Nlmf_Broadcast.yaml -c spec.yaml -g c -o nlmf_broadcast --package-name nlmf_broadcast
openapi-generator-cli generate -i ./specs/19.6.0/TS29572_Nlmf_DataExposure.yaml -c spec.yaml -g c -o nlmf_data_exposure --package-name nlmf_data_exposure
openapi-generator-cli generate -i ./specs/19.6.0/TS29572_Nlmf_Location.yaml -c spec.yaml -g c -o nlmf_location --package-name nlmf_location --skip-validate-spec

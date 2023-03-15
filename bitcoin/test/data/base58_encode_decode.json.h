namespace json_tests{ static unsigned const char base58_encode_decode[] = {
0x5b, 0x0a, 0x5b, 0x22, 0x22, 0x2c, 0x20, 0x22, 
0x22, 0x5d, 0x2c, 0x0a, 0x5b, 0x22, 0x36, 0x31, 
0x22, 0x2c, 0x20, 0x22, 0x32, 0x67, 0x22, 0x5d, 
0x2c, 0x0a, 0x5b, 0x22, 0x36, 0x32, 0x36, 0x32, 
0x36, 0x32, 0x22, 0x2c, 0x20, 0x22, 0x61, 0x33, 
0x67, 0x56, 0x22, 0x5d, 0x2c, 0x0a, 0x5b, 0x22, 
0x36, 0x33, 0x36, 0x33, 0x36, 0x33, 0x22, 0x2c, 
0x20, 0x22, 0x61, 0x50, 0x45, 0x72, 0x22, 0x5d, 
0x2c, 0x0a, 0x5b, 0x22, 0x37, 0x33, 0x36, 0x39, 
0x36, 0x64, 0x37, 0x30, 0x36, 0x63, 0x37, 0x39, 
0x32, 0x30, 0x36, 0x31, 0x32, 0x30, 0x36, 0x63, 
0x36, 0x66, 0x36, 0x65, 0x36, 0x37, 0x32, 0x30, 
0x37, 0x33, 0x37, 0x34, 0x37, 0x32, 0x36, 0x39, 
0x36, 0x65, 0x36, 0x37, 0x22, 0x2c, 0x20, 0x22, 
0x32, 0x63, 0x46, 0x75, 0x70, 0x6a, 0x68, 0x6e, 
0x45, 0x73, 0x53, 0x6e, 0x35, 0x39, 0x71, 0x48, 
0x58, 0x73, 0x74, 0x6d, 0x4b, 0x32, 0x66, 0x66, 
0x70, 0x4c, 0x76, 0x32, 0x22, 0x5d, 0x2c, 0x0a, 
0x5b, 0x22, 0x30, 0x30, 0x65, 0x62, 0x31, 0x35, 
0x32, 0x33, 0x31, 0x64, 0x66, 0x63, 0x65, 0x62, 
0x36, 0x30, 0x39, 0x32, 0x35, 0x38, 0x38, 0x36, 
0x62, 0x36, 0x37, 0x64, 0x30, 0x36, 0x35, 0x32, 
0x39, 0x39, 0x39, 0x32, 0x35, 0x39, 0x31, 0x35, 
0x61, 0x65, 0x62, 0x31, 0x37, 0x32, 0x63, 0x30, 
0x36, 0x36, 0x34, 0x37, 0x22, 0x2c, 0x20, 0x22, 
0x31, 0x4e, 0x53, 0x31, 0x37, 0x69, 0x61, 0x67, 
0x39, 0x6a, 0x4a, 0x67, 0x54, 0x48, 0x44, 0x31, 
0x56, 0x58, 0x6a, 0x76, 0x4c, 0x43, 0x45, 0x6e, 
0x5a, 0x75, 0x51, 0x33, 0x72, 0x4a, 0x44, 0x45, 
0x39, 0x4c, 0x22, 0x5d, 0x2c, 0x0a, 0x5b, 0x22, 
0x35, 0x31, 0x36, 0x62, 0x36, 0x66, 0x63, 0x64, 
0x30, 0x66, 0x22, 0x2c, 0x20, 0x22, 0x41, 0x42, 
0x6e, 0x4c, 0x54, 0x6d, 0x67, 0x22, 0x5d, 0x2c, 
0x0a, 0x5b, 0x22, 0x62, 0x66, 0x34, 0x66, 0x38, 
0x39, 0x30, 0x30, 0x31, 0x65, 0x36, 0x37, 0x30, 
0x32, 0x37, 0x34, 0x64, 0x64, 0x22, 0x2c, 0x20, 
0x22, 0x33, 0x53, 0x45, 0x6f, 0x33, 0x4c, 0x57, 
0x4c, 0x6f, 0x50, 0x6e, 0x74, 0x43, 0x22, 0x5d, 
0x2c, 0x0a, 0x5b, 0x22, 0x35, 0x37, 0x32, 0x65, 
0x34, 0x37, 0x39, 0x34, 0x22, 0x2c, 0x20, 0x22, 
0x33, 0x45, 0x46, 0x55, 0x37, 0x6d, 0x22, 0x5d, 
0x2c, 0x0a, 0x5b, 0x22, 0x65, 0x63, 0x61, 0x63, 
0x38, 0x39, 0x63, 0x61, 0x64, 0x39, 0x33, 0x39, 
0x32, 0x33, 0x63, 0x30, 0x32, 0x33, 0x32, 0x31, 
0x22, 0x2c, 0x20, 0x22, 0x45, 0x4a, 0x44, 0x4d, 
0x38, 0x64, 0x72, 0x66, 0x58, 0x41, 0x36, 0x75, 
0x79, 0x41, 0x22, 0x5d, 0x2c, 0x0a, 0x5b, 0x22, 
0x31, 0x30, 0x63, 0x38, 0x35, 0x31, 0x31, 0x65, 
0x22, 0x2c, 0x20, 0x22, 0x52, 0x74, 0x35, 0x7a, 
0x6d, 0x22, 0x5d, 0x2c, 0x0a, 0x5b, 0x22, 0x30, 
0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
0x30, 0x30, 0x30, 0x22, 0x2c, 0x20, 0x22, 0x31, 
0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 
0x31, 0x22, 0x5d, 0x2c, 0x0a, 0x5b, 0x22, 0x30, 
0x30, 0x30, 0x31, 0x31, 0x31, 0x64, 0x33, 0x38, 
0x65, 0x35, 0x66, 0x63, 0x39, 0x30, 0x37, 0x31, 
0x66, 0x66, 0x63, 0x64, 0x32, 0x30, 0x62, 0x34, 
0x61, 0x37, 0x36, 0x33, 0x63, 0x63, 0x39, 0x61, 
0x65, 0x34, 0x66, 0x32, 0x35, 0x32, 0x62, 0x62, 
0x34, 0x65, 0x34, 0x38, 0x66, 0x64, 0x36, 0x36, 
0x61, 0x38, 0x33, 0x35, 0x65, 0x32, 0x35, 0x32, 
0x61, 0x64, 0x61, 0x39, 0x33, 0x66, 0x66, 0x34, 
0x38, 0x30, 0x64, 0x36, 0x64, 0x64, 0x34, 0x33, 
0x64, 0x63, 0x36, 0x32, 0x61, 0x36, 0x34, 0x31, 
0x31, 0x35, 0x35, 0x61, 0x35, 0x22, 0x2c, 0x20, 
0x22, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 
0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 
0x47, 0x48, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x50, 
0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 
0x59, 0x5a, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 
0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6d, 0x6e, 0x6f, 
0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 
0x78, 0x79, 0x7a, 0x22, 0x5d, 0x2c, 0x0a, 0x5b, 
0x22, 0x30, 0x30, 0x30, 0x31, 0x30, 0x32, 0x30, 
0x33, 0x30, 0x34, 0x30, 0x35, 0x30, 0x36, 0x30, 
0x37, 0x30, 0x38, 0x30, 0x39, 0x30, 0x61, 0x30, 
0x62, 0x30, 0x63, 0x30, 0x64, 0x30, 0x65, 0x30, 
0x66, 0x31, 0x30, 0x31, 0x31, 0x31, 0x32, 0x31, 
0x33, 0x31, 0x34, 0x31, 0x35, 0x31, 0x36, 0x31, 
0x37, 0x31, 0x38, 0x31, 0x39, 0x31, 0x61, 0x31, 
0x62, 0x31, 0x63, 0x31, 0x64, 0x31, 0x65, 0x31, 
0x66, 0x32, 0x30, 0x32, 0x31, 0x32, 0x32, 0x32, 
0x33, 0x32, 0x34, 0x32, 0x35, 0x32, 0x36, 0x32, 
0x37, 0x32, 0x38, 0x32, 0x39, 0x32, 0x61, 0x32, 
0x62, 0x32, 0x63, 0x32, 0x64, 0x32, 0x65, 0x32, 
0x66, 0x33, 0x30, 0x33, 0x31, 0x33, 0x32, 0x33, 
0x33, 0x33, 0x34, 0x33, 0x35, 0x33, 0x36, 0x33, 
0x37, 0x33, 0x38, 0x33, 0x39, 0x33, 0x61, 0x33, 
0x62, 0x33, 0x63, 0x33, 0x64, 0x33, 0x65, 0x33, 
0x66, 0x34, 0x30, 0x34, 0x31, 0x34, 0x32, 0x34, 
0x33, 0x34, 0x34, 0x34, 0x35, 0x34, 0x36, 0x34, 
0x37, 0x34, 0x38, 0x34, 0x39, 0x34, 0x61, 0x34, 
0x62, 0x34, 0x63, 0x34, 0x64, 0x34, 0x65, 0x34, 
0x66, 0x35, 0x30, 0x35, 0x31, 0x35, 0x32, 0x35, 
0x33, 0x35, 0x34, 0x35, 0x35, 0x35, 0x36, 0x35, 
0x37, 0x35, 0x38, 0x35, 0x39, 0x35, 0x61, 0x35, 
0x62, 0x35, 0x63, 0x35, 0x64, 0x35, 0x65, 0x35, 
0x66, 0x36, 0x30, 0x36, 0x31, 0x36, 0x32, 0x36, 
0x33, 0x36, 0x34, 0x36, 0x35, 0x36, 0x36, 0x36, 
0x37, 0x36, 0x38, 0x36, 0x39, 0x36, 0x61, 0x36, 
0x62, 0x36, 0x63, 0x36, 0x64, 0x36, 0x65, 0x36, 
0x66, 0x37, 0x30, 0x37, 0x31, 0x37, 0x32, 0x37, 
0x33, 0x37, 0x34, 0x37, 0x35, 0x37, 0x36, 0x37, 
0x37, 0x37, 0x38, 0x37, 0x39, 0x37, 0x61, 0x37, 
0x62, 0x37, 0x63, 0x37, 0x64, 0x37, 0x65, 0x37, 
0x66, 0x38, 0x30, 0x38, 0x31, 0x38, 0x32, 0x38, 
0x33, 0x38, 0x34, 0x38, 0x35, 0x38, 0x36, 0x38, 
0x37, 0x38, 0x38, 0x38, 0x39, 0x38, 0x61, 0x38, 
0x62, 0x38, 0x63, 0x38, 0x64, 0x38, 0x65, 0x38, 
0x66, 0x39, 0x30, 0x39, 0x31, 0x39, 0x32, 0x39, 
0x33, 0x39, 0x34, 0x39, 0x35, 0x39, 0x36, 0x39, 
0x37, 0x39, 0x38, 0x39, 0x39, 0x39, 0x61, 0x39, 
0x62, 0x39, 0x63, 0x39, 0x64, 0x39, 0x65, 0x39, 
0x66, 0x61, 0x30, 0x61, 0x31, 0x61, 0x32, 0x61, 
0x33, 0x61, 0x34, 0x61, 0x35, 0x61, 0x36, 0x61, 
0x37, 0x61, 0x38, 0x61, 0x39, 0x61, 0x61, 0x61, 
0x62, 0x61, 0x63, 0x61, 0x64, 0x61, 0x65, 0x61, 
0x66, 0x62, 0x30, 0x62, 0x31, 0x62, 0x32, 0x62, 
0x33, 0x62, 0x34, 0x62, 0x35, 0x62, 0x36, 0x62, 
0x37, 0x62, 0x38, 0x62, 0x39, 0x62, 0x61, 0x62, 
0x62, 0x62, 0x63, 0x62, 0x64, 0x62, 0x65, 0x62, 
0x66, 0x63, 0x30, 0x63, 0x31, 0x63, 0x32, 0x63, 
0x33, 0x63, 0x34, 0x63, 0x35, 0x63, 0x36, 0x63, 
0x37, 0x63, 0x38, 0x63, 0x39, 0x63, 0x61, 0x63, 
0x62, 0x63, 0x63, 0x63, 0x64, 0x63, 0x65, 0x63, 
0x66, 0x64, 0x30, 0x64, 0x31, 0x64, 0x32, 0x64, 
0x33, 0x64, 0x34, 0x64, 0x35, 0x64, 0x36, 0x64, 
0x37, 0x64, 0x38, 0x64, 0x39, 0x64, 0x61, 0x64, 
0x62, 0x64, 0x63, 0x64, 0x64, 0x64, 0x65, 0x64, 
0x66, 0x65, 0x30, 0x65, 0x31, 0x65, 0x32, 0x65, 
0x33, 0x65, 0x34, 0x65, 0x35, 0x65, 0x36, 0x65, 
0x37, 0x65, 0x38, 0x65, 0x39, 0x65, 0x61, 0x65, 
0x62, 0x65, 0x63, 0x65, 0x64, 0x65, 0x65, 0x65, 
0x66, 0x66, 0x30, 0x66, 0x31, 0x66, 0x32, 0x66, 
0x33, 0x66, 0x34, 0x66, 0x35, 0x66, 0x36, 0x66, 
0x37, 0x66, 0x38, 0x66, 0x39, 0x66, 0x61, 0x66, 
0x62, 0x66, 0x63, 0x66, 0x64, 0x66, 0x65, 0x66, 
0x66, 0x22, 0x2c, 0x20, 0x22, 0x31, 0x63, 0x57, 
0x42, 0x35, 0x48, 0x43, 0x42, 0x64, 0x4c, 0x6a, 
0x41, 0x75, 0x71, 0x47, 0x47, 0x52, 0x65, 0x57, 
0x45, 0x33, 0x52, 0x33, 0x43, 0x67, 0x75, 0x75, 
0x77, 0x53, 0x6a, 0x77, 0x36, 0x52, 0x48, 0x6e, 
0x33, 0x39, 0x73, 0x32, 0x79, 0x75, 0x44, 0x52, 
0x54, 0x53, 0x35, 0x4e, 0x73, 0x42, 0x67, 0x4e, 
0x69, 0x46, 0x70, 0x57, 0x67, 0x41, 0x6e, 0x45, 
0x78, 0x36, 0x56, 0x51, 0x69, 0x38, 0x63, 0x73, 
0x65, 0x78, 0x6b, 0x67, 0x59, 0x77, 0x33, 0x6d, 
0x64, 0x59, 0x72, 0x4d, 0x48, 0x72, 0x38, 0x78, 
0x39, 0x69, 0x37, 0x61, 0x45, 0x77, 0x50, 0x38, 
0x6b, 0x5a, 0x37, 0x76, 0x63, 0x63, 0x58, 0x57, 
0x71, 0x4b, 0x44, 0x76, 0x47, 0x76, 0x33, 0x75, 
0x31, 0x47, 0x78, 0x46, 0x4b, 0x50, 0x75, 0x41, 
0x6b, 0x6e, 0x38, 0x4a, 0x43, 0x50, 0x50, 0x47, 
0x44, 0x4d, 0x66, 0x33, 0x76, 0x4d, 0x4d, 0x6e, 
0x62, 0x7a, 0x6d, 0x36, 0x4e, 0x68, 0x39, 0x7a, 
0x68, 0x31, 0x67, 0x63, 0x4e, 0x73, 0x4d, 0x76, 
0x48, 0x33, 0x5a, 0x4e, 0x4c, 0x6d, 0x50, 0x35, 
0x66, 0x53, 0x47, 0x36, 0x44, 0x47, 0x62, 0x62, 
0x69, 0x32, 0x74, 0x75, 0x77, 0x4d, 0x57, 0x50, 
0x74, 0x68, 0x72, 0x34, 0x62, 0x6f, 0x57, 0x77, 
0x43, 0x78, 0x66, 0x37, 0x65, 0x77, 0x53, 0x67, 
0x4e, 0x51, 0x65, 0x61, 0x63, 0x79, 0x6f, 0x7a, 
0x68, 0x4b, 0x44, 0x44, 0x51, 0x51, 0x31, 0x71, 
0x4c, 0x35, 0x66, 0x51, 0x46, 0x55, 0x57, 0x35, 
0x32, 0x51, 0x4b, 0x55, 0x5a, 0x44, 0x5a, 0x35, 
0x66, 0x77, 0x33, 0x4b, 0x58, 0x4e, 0x51, 0x4a, 
0x4d, 0x63, 0x4e, 0x54, 0x63, 0x61, 0x42, 0x37, 
0x32, 0x33, 0x4c, 0x63, 0x68, 0x6a, 0x65, 0x4b, 
0x75, 0x6e, 0x37, 0x4d, 0x75, 0x47, 0x57, 0x35, 
0x71, 0x79, 0x43, 0x42, 0x5a, 0x59, 0x7a, 0x41, 
0x31, 0x4b, 0x6a, 0x6f, 0x66, 0x4e, 0x31, 0x67, 
0x59, 0x42, 0x56, 0x33, 0x4e, 0x71, 0x79, 0x68, 
0x51, 0x4a, 0x33, 0x4e, 0x73, 0x37, 0x34, 0x36, 
0x47, 0x4e, 0x75, 0x66, 0x39, 0x4e, 0x32, 0x70, 
0x51, 0x50, 0x6d, 0x48, 0x7a, 0x34, 0x78, 0x70, 
0x6e, 0x53, 0x72, 0x72, 0x66, 0x43, 0x76, 0x79, 
0x36, 0x54, 0x56, 0x56, 0x7a, 0x35, 0x64, 0x34, 
0x50, 0x64, 0x72, 0x6a, 0x65, 0x73, 0x68, 0x73, 
0x57, 0x51, 0x77, 0x70, 0x5a, 0x73, 0x5a, 0x47, 
0x7a, 0x76, 0x62, 0x64, 0x41, 0x64, 0x4e, 0x38, 
0x4d, 0x4b, 0x56, 0x35, 0x51, 0x73, 0x42, 0x44, 
0x59, 0x22, 0x5d, 0x0a, 0x5d, 0x0a, };}

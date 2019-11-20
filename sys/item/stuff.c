#include <ansi.h>

mapping Locate = ([
	"14"	: ({ 50,118,51,109,58,126,62,103,65,93,71,129,74,117,81,117,90,133,109,130,109,159,118,134,119,159,130,173,145,177,152,164,166,177,171,97,176,98,177,132,179,99,179,163,182,106,184,123,186,145,186,162,202,96,208,109,213,102,240,133,49,121,51,106,61,126,64,99,66,77,71,97,78,69,78,118,85,64,87,97,88,89,91,147,92,60,92,135,102,69,102,85,104,144,106,73,107,114,112,162,136,174,166,177,179,163,183,105,186,162,188,136,189,102,202,105,206,95,209,109,66,125,70,98,82,130,102,122,108,157,112,137,113,163,128,135,134,153,134,173,151,180,157,144,169,121,176,167,180,127,185,166,189,112,192,134,208,108,212,137,222,95,227,142,248,92,253,111,61,126,81,116,104,144,107,102,120,161,145,177,169,173,176,164,184,124,186,145,186,162,194,133,203,110,210,106,220,110, }),
	"15"	: ({ 68,91,68,110,81,110,88,80,89,61,89,119,96,76,99,67,103,120,108,87,108,105,114,55,117,73,121,176,122,55,123,51,125,137,129,67,129,100,132,95,138,170,141,116,149,172,151,105,151,125,155,130,160,184,162,146,168,118,174,189,70,87,81,73,82,98,85,85,89,61,93,80,99,63,99,79,103,71,114,91,115,55,121,176,122,55,122,74,125,94,127,71,131,97,132,60,135,93,135,171,141,115,142,170,146,177,150,126,151,111,153,123,159,182,163,116,171,195,174,189,82,111,85,73,92,82,94,119,116,91,121,140,127,96,132,126,141,116,152,111,68,102,89,95,89,119,103,97,114,138,121,96,130,102,133,96,133,139,141,115,151,180,168,122,170,195, }),
	"21"	: ({ 51,106,56,101,60,88,69,63,74,82,76,87,80,108,88,112,90,50,93,64,104,68,104,97,112,72,116,136,127,124,130,135,132,81,138,50,148,109,151,42,156,47,156,111,160,126,160,130,183,56,183,71,185,76,191,106,196,84,196,90, }),
	"41"	: ({ 55,100,59,84,59,93,60,104,61,82,68,116,76,56,78,125,80,84,83,125,86,85,87,68,89,87,91,52,91,66,92,116,95,89,97,134,98,117,100,133,102,89,103,133,106,60,108,90,110,47,112,65,112,116,117,99,118,79,118,129,122,112,124,81,125,44,126,65,128,125,129,43,130,65,131,77,131,125,132,44,133,106,134,98,135,112,137,129,139,38,140,53,145,42,145,69,146,107,149,98,151,127,157,52,157,62,158,73,159,47,166,78,166,112,167,98,168,72,171,110,172,82,179,100,180,77,190,95,192,90,195,77,197,81, }),
	"42"	: ({ 104,210,114,227,123,88,128,217,134,96,143,107,145,156,152,119,154,158,155,98,156,145,157,128,159,256,162,102,165,204,166,120,166,209,167,250,170,151,178,103,179,122,180,137,183,167,183,233,185,104,185,133,190,206,194,208,198,108,206,115,206,120,207,183,207,190,209,252,210,138,218,222,218,253,221,149,227,152,240,156,246,237,255,168,258,142,262,221,263,167,265,178,267,228,269,257,272,144,276,157,279,257,281,232,290,147,309,134,315,167,320,174,321,192,328,183,330,202,338,154,342,104,345,151,352,137,353,118,357,172,363,126,368,178,374,132,374,173,374,194,383,195,387,187,394,182,396,153, }),
	"43"	: ({ 27,97,28,96,34,91,38,103,47,84,52,96,59,95,65,75,66,93,72,72,72,93,73,68,78,99,85,80,87,78,87,102,90,80,90,97,93,101,98,98,104,111,108,75,109,74,112,163,113,113,113,153,114,95,117,77,121,60,121,158,125,58,126,85,126,147,129,145,133,158,139,128,141,69,142,127,145,72,146,150,147,148,150,47,150,162,154,69,156,135,157,72,162,165,165,169,166,121,166,144,169,47,170,141,173,76,174,158,175,53,176,137,186,180,190,84,191,162,192,166,196,120,201,85,204,75,205,106,224,106, }),
	"81"	: ({ 45,49,49,52,57,29,58,77,60,64,62,43,64,72,66,71,68,87,78,62,82,67,83,61,87,32,87,88,90,74,91,89,94,57,97,50,106,72,110,71,114,98,115,94,117,100,125,73,125,114,127,67,128,78,135,88,138,103,143,99,147,96,159,105,161,85,164,123,164,132,168,135,169,85,177,120,179,138,180,96,180,105,194,162,199,133,204,166,210,143,213,172,216,147,216,160,218,133,225,175,234,153,236,142,238,166,239,142,216,147,218,133,225,175,239,142, }), 
	"82"	: ({ 52,86,56,122,58,102,59,111,65,79,74,118,83,143,93,140,95,153,106,98,115,160,127,92,128,126,136,133,152,94,154,138,155,116,162,157,163,136,165,104,168,124,177,116,178,163,183,116,186,154,188,111,199,126,202,143,204,132,206,115,51,90,58,128,62,110,62,114,64,82,67,125,78,120,85,115,93,140,109,98,113,162,129,93,133,145,141,134,142,149,148,94,148,106,152,152,157,120,162,157,175,160,179,116,184,111,184,159,188,72,189,145,194,110,200,132,202,143,206,136, }), 
	"111"	: ({ 33,98,46,97,54,109,57,84,60,113,62,132,65,87,66,105,73,111,73,134,74,142,77,95,87,148,102,152,109,151,123,178,129,165,129,181,154,170,163,141,163,160,165,128,168,135,171,147,176,135,206,125,210,119,216,119,224,113,48,94,65,87,79,99,87,92,102,87,106,102,109,90,123,99,142,90,156,107,186,111,204,102,216,123,223,113,228,96, }),
	"112"	: ({ 54,77,59,78,68,97,69,83,71,95,77,102,87,98,91,122,93,126,97,108,104,130,113,125,122,128,135,108,138,114,145,103,154,104,162,95,165,82,169,106,174,65,185,101,186,72,194,119,195,83,200,108,210,116,212,90,223,122,225,98,53,93,70,83,77,102,98,73,99,125,113,48,121,60,126,44,135,49,144,103,152,55,154,81,158,104,166,55,175,92, }),
	"131"	: ({ 62,93,65,99,70,75,70,94,80,52,84,103,85,83,86,134,93,41,93,111,96,127,96,137,101,33,102,81,107,93,114,71,124,59,129,26,141,114,144,38,145,65,150,48,150,100,157,74,157,105,162,88,169,112,170,70,174,81,179,108,55,69,61,88,63,77,66,92,66,101,78,54,83,129,84,102,88,79,92,140,93,105,94,41,94,63,98,130,108,37,109,59,109,79,111,120,121,84,123,56,128,125,141,114,147,71,150,48,155,104,160,79,172,72,175,110,177,91,181,98,55,83,62,90,72,79,73,97,83,121,84,70,89,136,91,82,96,127,108,37,109,110,110,78,112,92,126,25,126,57, }),
	"132"	: ({ 33,67,47,68,50,53,57,47,66,64,71,49,73,105,74,65,87,25,88,117,91,58,96,47,99,18,102,133,107,122,109,22,119,30,119,70,121,99,122,118,123,56,127,37,130,75,130,96,133,86,134,51,137,45,157,93,160,73,166,65,40,68,44,78,63,62,73,91,73,105,78,48,85,26,88,117,91,104,96,47,99,18,101,46,101,133,102,111,105,74,106,120,107,61,112,50,113,24,114,123,115,110,123,56,124,35,124,87,132,39,134,52,137,45,146,92,161,64,168,84,42,68,58,90,61,77,68,81,72,105,74,90,96,121,102,111,105,98,114,114,122,118,123,101,157,93,159,67,167,65, }),
	"141"	: ({ 49,69,62,72,71,83,79,85,79,99,93,105,104,100,117,123,117,134,127,116,135,137,163,154,172,141,172,149,193,156,193,174,204,144,204,200,208,118,208,156,208,174,213,187,215,209,216,116,216,182,225,211,230,127,230,206,240,184,248,170,50,58,51,48,62,72,66,61,112,66,129,119,129,132,134,136,135,83,135,121,139,153,143,126,145,74,153,129,161,151,162,80,168,118,170,150,172,99,184,166,199,177,201,163,204,195,208,170,213,184,222,182,226,210,227,205,245,183,246,196, }),
	"142"	: ({ 35,99,40,94,54,95,59,94,70,104,73,121,74,97,84,65,90,56,103,91,110,94,115,37,129,29,133,37,141,95,143,163,147,33,148,114,150,163,157,117,163,164,177,95,179,162,182,60,186,71,187,82,210,127,224,131,242,122,255,100, }),
	"155"	: ({ 53,85,66,91,69,75,73,71,76,77,86,87,94,80,95,61,114,57,125,42,135,47,160,164,161,156,162,150,170,160,170,178,177,160,188,184,197,189,213,184,228,192,242,204,251,184,259,210,263,194,273,211,274,181,278,167,282,141,291,193,67,86,75,70,83,88,95,61,96,78,111,57,123,131,129,53,162,162,175,161,178,184,182,173,189,162,212,174,232,177,261,162,284,156,298,164, }),
	"171"	: ({ 95,174,98,158,105,178,109,154,110,172,115,155,127,155,128,142,129,131,134,71,139,123,141,139,145,52,148,87,149,126,155,86,157,74,160,101,160,125,166,117,168,44,181,97,187,52,198,75,199,110,201,59,204,90,211,116,229,130,249,126,95,174,97,158,128,132,128,171,141,139,148,102,160,101,162,118,184,109,194,111,209,112,219,99,228,130,258,131,263,158,280,190,283,133,286,142,291,170,138,69,168,72,184,90,197,56,198,75,198,109,212,114,228,111,240,127,254,128,263,158,269,166,283,122,294,166,299,172, }),
	"172"	: ({ 77,31,77,47,86,51,88,29,100,34,100,49,110,82,116,54,116,100,127,59,127,75,127,89,132,101,146,118,149,109,152,90,171,150,176,124,186,148,193,148,202,156,215,162,219,149,222,178,225,149,228,176,231,182,236,174,254,162,264,150,88,52,100,34,102,61,105,78,116,103,117,135,121,85,125,121,127,67,132,100,140,136,142,145,152,91,161,144,184,130,193,148,199,135,219,161,227,174,231,182,237,156,260,144,260,155,105,59,113,84,117,127,124,67,127,74,131,137,132,100,133,117,139,137,161,144,175,151,186,148,209,136,222,147,240,156, }),
	"173"	: ({ 42,110,55,107,60,113,72,107,86,101,100,98,106,91,118,94,126,145,131,127,135,157,139,90,142,88,142,109,144,150,147,106,147,113,153,150,163,170,167,161,171,144,176,164,184,146,193,131,194,181,205,187,207,122,207,159,211,107,216,159,47,110,62,103,91,101,106,91,139,90,141,131,147,112,156,137,157,171,174,103,176,164,193,131,198,93,218,134,222,105,72,107,89,99,105,95,128,143,129,95,139,90,140,158,148,111,149,123,150,134,151,164,153,95,170,164,186,147,207,149, }),
	"174"	: ({ 50,60,59,73,61,61,71,87,76,76,86,84,98,105,105,89,118,104,120,93,132,105,137,89,141,114,149,119,150,92,150,100,159,124,173,178,176,132,177,120,182,157,184,191,188,137,206,157,212,208,226,142,228,208,246,182,246,197,254,155,63,66,80,79,80,93,114,102,137,89,149,119,151,101,159,124,173,160,204,179,224,211,230,144,248,202,250,155,265,173,64,68,80,78,87,98,89,87,109,106,131,105,152,102,159,139,172,150,175,132,178,184,200,198,201,168,215,209,240,205,246,182,265,173, }),
	"181"	: ({ 28,153,41,154,46,168,49,139,55,127,58,169,70,123,76,155,80,187,94,110,95,152,96,201,102,150,104,177,104,187,105,129,111,126,117,105,120,200,124,172,126,195,131,162,133,170,133,186,138,141,138,154,157,134,199,31,219,38,229,50, }),
	"182"	: ({ 59,73,76,60,78,73,82,57,98,48,110,69,118,31,125,34,129,101,130,44,133,86,135,67,136,115,137,109,140,87,144,29,146,141,146,156,150,38,152,67,153,128,155,50,162,65,164,141,171,57,180,124,182,117,183,76,185,63,206,72, }),
	"211"	: ({ 28,90,45,119,48,94,50,85,53,102,54,74,63,130,64,71,64,88,66,125,68,96,82,59,84,152,85,59,99,159,103,63,111,158,128,158,129,39,141,142,158,49,167,123,175,143,178,71,183,131,187,66,194,116,202,91,203,117,210,92,27,91,39,94,44,113,50,85,53,75,53,102,63,72,67,97,67,114,85,61,111,156,127,34,128,158,142,141,152,45,157,49,166,141,170,80,174,143,175,130,177,89,178,71,184,131,187,66,196,118,197,108,202,97,206,94,209,84, }),
	"231"	: ({ 26,105,39,95,50,123,54,91,57,132,66,118,67,101,71,143,86,150,88,57,104,121,105,53,111,51,115,173,117,73,118,63,121,34,122,99,129,77,130,153,132,92,133,22,139,133,140,57,143,158,145,23,149,44,170,40,180,54,189,53,34,97,40,97,55,91,66,90,78,138,82,63,85,128,86,151,88,134,92,55,97,130,108,56,117,114,124,56,125,29,128,46,129,69,131,98,139,61,143,102,145,24,147,42,148,122,152,161,155,52,156,28,158,127,162,67,178,60,189,56,50,123,63,126,73,136,82,116,82,152,89,125,99,126,104,121,126,101,140,140,145,85,148,149,160,93,166,99,174,110, }),
	"241" 	: ({ 51,73,69,56,77,44,83,93,84,110,86,124,87,95,88,85,98,139,99,38,105,88,106,97,107,129,109,71,112,83,114,131,115,32,120,62,125,32,126,124,133,47,135,110,139,118,144,111,152,105,155,52,159,60,159,98,160,80,165,88, }),
	"242"	: ({ 49,67,54,67,69,74,70,52,73,88,77,117,83,122,84,48,85,85,85,100,93,119,94,130,98,49,115,54,119,102,119,116,121,94,122,34,130,37,130,121,131,73,133,89,135,52,136,112,138,64,139,89,151,79,154,73,158,56,167,62,49,68,53,68,63,58,73,50,82,50,84,119,86,125,94,47,95,115,100,130,103,53,103,68,107,72,107,118,116,114,117,106,121,101,122,34,124,95,132,60,135,49,135,67,135,73,136,86,136,112,137,95,147,89,148,65,151,79,159,57,53,67,70,73,84,48,84,116,95,118,102,87,108,69,116,49,119,114,126,97,132,73,133,89,135,55,143,81,157,54, }),
	"243"	: ({ 67,95,68,112,75,88,81,86,84,75,89,68,104,57,128,46,134,55,144,45,155,55,164,46,174,167,175,63,176,89,186,167,194,90,195,164,199,83,202,50,202,166,204,105,206,120,213,57,215,141,216,123,217,168,219,155,223,67,233,153, }),
	"251"	: ({ 62,175,72,196,95,209,108,207,130,97,133,81,143,79,148,105,148,112,155,156,158,73,170,78,174,142,177,76,178,68,191,75,192,41,202,139,204,57,205,132,207,120,213,33,219,64,222,45,230,98,231,107,234,74,241,105,252,84,254,95,69,183,107,207,132,97,135,106,153,79,155,156,156,147,164,69,172,74,174,141,182,89,185,134,189,44,189,98,191,133,193,38,203,40,208,57,205,132,205,139,206,121,213,33,221,57,226,40,228,74,246,81,251,99,253,87, }),
	"261"	: ({ 45,109,49,98,58,121,62,127,66,105,75,131,87,132,89,60,93,117,109,45,111,90,112,135,115,58,116,153,118,104,120,83,120,114,121,60,124,159,135,69,142,81,143,107,146,156,149,92,149,138,156,130,156,149,160,113,162,149,170,142,44,99,53,108,62,127,66,105,76,121,92,119,97,130,105,129,124,159,130,139,142,155,157,151,172,113,174,135,185,122, }),
	"262"	: ({ 76,63,78,49,92,56,95,45,103,48,104,36,108,32,114,100,122,80,126,65,129,42,133,50,138,110,141,82,152,122,164,124,176,126,188,127,192,115,195,142,199,136,209,154,213,157,215,171,225,152,225,162,225,176,239,171,244,188,248,175,87,67,95,45,96,29,101,67,108,32,117,34,124,106,130,80,131,51,157,106,178,127,192,127,214,170,218,142,243,186, }),
	"263"	: ({ 55,51,71,48,88,52,94,63,102,55,104,71,106,80,111,124,114,130,128,135,129,82,131,75,132,111,136,93,137,122,137,136,144,100,147,91,154,119,174,137,175,117,178,132,192,122,210,146,217,129,224,139,225,156,228,165,235,171,249,161,78,50,88,53,91,61,102,55,112,66,127,77,132,82,135,93,142,114,165,128,177,127,207,130,225,156,235,171,244,152, }),
	"265"	: ({ 65,83,67,61,67,99,70,78,70,109,73,50,74,112,82,85,83,69,85,89,90,80,91,103,93,44,94,66,94,99,96,90,98,34,106,32,110,56,114,72,118,79,120,32,121,47,122,70,126,80,135,82,136,41,136,45,155,110,179,95,72,79,90,80,106,116,109,96,110,135,117,99,135,127,145,131,145,166,151,155,161,133,175,84,185,161,187,86,200,157, }),
	"266"	: ({ 57,111,65,90,77,81,89,92,95,61,96,81,99,93,100,70,105,50,125,60,135,121,138,29,138,160,143,25,145,164,147,119,152,17,158,89,158,147,158,173,160,110,162,163,163,35,164,141,165,81,168,86,177,178,181,139,195,140,197,123,66,102,85,112,104,118,118,122,125,153,129,135,146,194,151,180,156,167,177,178, }),
	"271"	: ({ 64,101,64,117,68,126,72,136,94,75,96,129,110,67,110,120,110,132,116,107,119,119,120,111,121,55,130,153,139,54,151,50,152,78,160,66,162,83,166,111,168,128,169,83,170,118,180,55,184,82,197,115,201,63,203,114,211,80,65,112,71,94,81,114,81,140,88,99,103,126,116,107,120,114,131,155,155,161,162,62,176,56,184,139,187,128,188,192,192,56,197,107,198,98,199,115,200,64,200,161,203,90,204,180,207,141,209,153,214,172,216,73,225,160,226,152,228,111,65,112,81,139,85,118,108,132,119,116,131,154,156,152,163,175,182,191,191,192,209,150,214,172,226,153,229,110,264,128, }),
	"272"	: ({ 35,118,47,106,53,97,58,109,59,97,61,105,67,107,87,113,87,130,90,153,91,168,97,151,98,126,100,173,107,125,107,157,119,138,122,160,123,144,127,183,130,165,141,158,154,169,164,167,166,153,171,165,174,149,184,128,186,145,36,118,49,106,50,99,54,96,58,109,62,104,76,105,86,130,92,141,97,123,97,170,105,176,108,142,111,157,118,174,121,137,127,180,140,168,154,169,161,138,165,123,166,153,166,167,167,111,186,103,188,81,194,93,207,87,218,103,231,90,46,106,62,109,96,170,98,123,98,151,105,140,111,160,118,138,127,143,130,165,153,169,164,167,168,155, }),
	"281" 	: ({ 26,147,33,143,34,156,43,133,44,167,46,145,50,156,51,129,53,143,56,123,58,174,59,153,60,142,61,122,63,181,65,141,66,154,68,187,69,113,71,131,71,189,74,131,76,182,77,112,78,160,79,180,80,184,81,145,82,196,84,104,84,133,84,182,86,124,87,159,88,135,89,100,90,124,92,191,94,94,94,133,94,145,96,111,98,110,99,96,99,135,99,181,101,166,102,88,102,113,103,152,103,179,106,142,107,130,108,89,109,173,110,82,111,127,112,98,115,167,118,89,118,116,119,165,121,82,122,97,123,85,125,161,128,99,130,151,133,101,138,132,139,109,139,143,140,128,142,107,147,139, }), 
	"282"	: ({ 85,59,96,70,105,57,109,64,128,66,129,73,134,107,138,70,119,51,150,56,166,120,165,149,133,148,132,163,108,160,116,159,122,143,137,147,129,106,85,103,79,90,86,129,101,138,122,123, }), 
	"283"	: ({ 32,148,46,154,64,142,54,169,66,176,71,158,83,165,93,155,73,153,94,135,96,112,115,105,131,87,146,75,155,89,174,70,201,63,220,57,180,36,168,50,139,119,120,126,104,133, }), 
	"284"	: ({ 69,33,148,125,157,143,163,162,174,112,175,168,177,100,197,112,197,130,197,139,201,184,203,129,207,142,216,168,220,135,222,186,224,162,224,199,225,144,235,181,236,135,239,190,241,169,248,183,251,149,261,155,265,172,269,185,274,165, }),
	"311"	: ({ 84,120,100,99,102,113,115,95,123,158,129,108,132,90,135,136,136,160,140,146,143,68,143,93,150,137,153,56,154,82,156,160,161,74,165,122,169,111,174,52,175,116,190,74,192,60,194,94,196,106,200,57,203,71,212,76,216,99,224,88,102,57,118,59,95,73,89,89,105,89,96,106,92,135,120,135,121,160,141,156,177,150,204,124,172,119,207,106,190,94,219,82,192,64,200,57,142,69,164,61,155,84,115,64,205,95,140,146,115,106,175,115,216,99,135,136,102,113,202,81,87,130,95,117,100,98,101,88,111,132,116,107,125,145,127,154,138,135,139,106,149,165,152,126,153,111,170,115,179,123,180,148,202,123, }),
	"312"	: ({ 48,79,62,82,65,55,65,68,78,68,82,61,93,47,95,59,108,37,110,93,113,109,116,38,121,104,128,59,134,41,138,57,145,91,150,43,165,115,167,103,168,88,170,47,172,60,183,59,188,108,192,81,197,71,203,108,208,95,212,84,171,137,163,136,145,131,153,124,165,115,153,104,126,86,179,77,171,60,170,47,154,35,128,59,117,35,108,37,90,58,67,57,56,87,49,94,71,105,90,138,119,135,117,162,155,152,121,111,95,73,41,93,153,120,55,78,74,74,79,63,90,76,90,90,103,90,111,48,113,109,128,43,144,44,146,91,160,114,165,90,170,47,172,60,183,99,187,66,201,87,202,113,214,90, }),
	"313"	: ({ 18,87,30,93,35,82,43,109,50,99,58,93,69,98,70,83,83,87,84,142,85,103,93,113,96,133,103,148,109,122,113,155,135,133,135,152,142,136,154,64,159,122,166,54,175,119,182,122,185,64,198,110,199,79,201,96,213,100,223,88,19,93,43,109,44,63,52,98,61,113,62,124,66,59,78,134,82,57,84,142,96,73,104,90,106,139,129,153,138,130,141,107,145,93,155,118,165,130,168,86,170,119,173,54,175,105,176,128,184,75,185,95,193,104,207,83,208,75,223,91,17,90,32,95,43,109,59,104,71,121,85,137,101,129,103,148,118,150,120,39,136,144,146,123,148,62,161,70,162,123,166,54,179,111,189,65,197,77,210,100,215,81, }),
	"381"	: ({ 73,72,84,116,88,71,90,90,94,102,106,123,110,100,118,53,120,138,152,64,156,117,160,85,161,103,162,46,165,113,170,61,170,130,177,84,178,55,180,72,184,101,186,126,196,70,197,116,199,121,203,137,211,102,214,131,231,92,235,109,87,86,96,113,97,130,104,73,107,94,116,137,123,60,125,46,126,31,129,189,131,145,143,175,147,144,151,39,154,158,164,40,166,89,184,75,194,62, }),
	"383"	: ({ 69,46,83,28,91,62,96,29,98,79,100,92,100,126,102,11,108,45,114,62,114,91,115,22,121,134,122,49,122,145,126,112,130,103,131,127,132,29,134,70,141,147,151,95,156,127,159,141,164,98,167,115,170,82,188,92,207,93,225,97,81,52,87,24,98,49,99,77,105,72,106,10,115,54,116,93,119,24,121,125,121,134,130,103,136,62,139,145,151,80,152,104,158,142,166,110,171,91,205,92, }),
	"385"	: ({ 28,94,33,109,45,118,49,70,49,86,60,111,60,129,64,87,67,65,70,50,75,119,82,56,82,142,94,44,107,142,113,58,115,33,125,60,126,134,130,33,132,119,134,22,151,21,152,134,157,115,168,111,181,105,187,90,188,56,203,99,29,104,38,88,47,111,59,83,63,55,73,120,77,94,82,142,91,46,94,117,99,101,111,137,126,131,129,99,145,87,152,134,169,88,170,107,188,100,200,101, }),
	"501"	: ({ 48,135,54,133,56,109,57,133,73,136,76,138,77,114,78,137,80,114,86,143,87,115,99,146,101,78,106,77,131,116,137,112,142,115,145,47,147,42,147,187,148,118,150,189,155,175,163,27,166,208,170,210,172,143,173,139,182,208,188,167,191,162,192,198,193,58,193,192,195,54,195,165,196,191,198,53,200,49,201,191,205,134,206,192,209,133,211,133,215,110,219,178,220,81,221,84,221,177,224,178,236,113,242,95,252,141,254,130,254,135,256,142,261,129,262,109,280,131,300,123, }),
	"502"	: ({ 48,135,52,134,57,133,59,111,73,136,77,138,85,109,87,107,87,143,96,145,99,146,101,78,106,76,130,111,134,110,137,112,141,188,144,115,146,46,146,187,147,42,149,194,150,189,163,27,163,66,163,210,166,63,166,139,166,208,170,138,170,210,172,68,172,209,178,209,181,208,184,207,192,197,193,192,195,54,196,191,198,53,200,49,200,190,202,192,203,134,205,134,206,192,207,190,208,132,209,187,233,110,237,109,253,131,253,137,257,141,258,128,262,109, }),
	"503"	: ({ 48,135,52,134,58,135,76,139,79,110,80,142,81,137,84,109,87,107,87,143,88,115,96,145,99,146,106,76,132,110,135,110,144,188,145,49,146,115,147,42,148,187,149,195,163,28,171,209,180,208,184,207,188,163,191,162,193,192,195,163,196,191,197,53,197,61,199,51,200,48,201,191,206,192,207,64,207,190,223,178,236,164,239,163,243,97,256,136,257,140,263,106,266,106,280,131, }),
	"504"	: ({ 47,134,51,133,54,134,54,147,57,107,57,111,57,149,58,133,59,105,61,150,63,154,69,159,72,161,73,136,75,137,76,160,78,137,79,156,83,156,87,143,95,79,96,81,99,83,106,109,110,107,113,109,115,111,126,57,128,86,129,113,130,84,133,82,134,110,136,86,137,111,139,210,141,211,143,42,143,115,145,190,147,42,147,189,149,117,156,117,158,212,159,115,161,24,162,116,163,65,165,208,166,63,166,139,168,207,171,138,172,68,173,139,174,67,174,102,177,104,179,210,181,208,182,147,183,141,185,74,186,145,187,149,188,163,190,53,190,75,191,162,192,48,192,195,193,102,193,192,193,193,194,58,195,163,196,191, }),
	"505"	: ({ 47,134,48,140,49,122,53,134,54,147,55,134,57,149,58,111,61,111,61,150,62,153,65,157,70,160,71,140,73,136,73,162,76,138,76,159,79,136,80,152,80,156,84,157,86,143,96,81,96,144,97,83,99,145,107,108,111,107,111,116,115,111,124,59,126,58,129,113,130,190,131,195,133,120,134,110,135,61,137,111,141,62,141,202,141,211,146,120,147,189,150,189,150,193,152,176,156,209,158,212,164,213,165,141,165,208,168,138,168,207,170,104,171,103,173,139,174,102,175,42,178,41,179,210,180,142,181,208,182,147,186,145,187,124,188,123,188,163,189,51,190,123,191,48,191,162,192,195,193,102,194,58,194,101,194,162, }),
	"506"	: ({ 48,139,49,122,55,134,57,107,58,135,58,149,61,110,62,153,70,160,74,136,81,110,81,156,87,143,88,115,91,111,95,147,107,108,112,114,114,111,122,66,126,57,127,113,129,84,130,190,131,192,134,82,134,110,136,86,137,111,137,116,141,43,147,188,148,42,151,189,160,220,161,221,167,26,167,207,171,104,177,104,183,207,185,124,188,168,189,51,190,55,191,103,191,125,193,48,193,193,194,58,196,164,197,190,200,190,205,133,205,188,208,132,210,137,223,139,227,167,228,138,231,139,254,134,255,118,258,128,261,129,266,131,272,109,276,110,281,110, }),
	"507"	: ({ 45,114,46,118,49,122,49,135,54,141,58,135,59,149,62,153,70,160,74,136,76,160,77,138,81,156,84,143,85,159,88,143,95,147,97,145,99,147,107,108,111,107,112,114,114,110,118,112,127,116,128,85,129,113,130,190,131,192,132,82,135,110,136,85,137,111,137,116,143,115,146,189,149,117,149,188,150,101,152,192,154,176,157,209,158,116,158,220,159,71,161,115,163,119,164,143,165,71,167,207,168,139,171,138,172,67,173,72,173,102,173,107,173,201,173,209,174,141,176,202,178,106,179,215,180,148,180,208,181,141,183,207,185,145,187,123,187,149,188,74,188,168,189,78,189,162,190,126,193,161,193,193,195,101,196,164, }),
	"508"	: ({ 37,127,40,132,42,129,51,134,57,136,58,107,58,150,61,110,62,151,63,155,76,159,77,138,81,157,82,114,85,109,85,159,87,143,95,79,98,146,106,109,107,84,111,108,115,111,118,110,134,111,135,111,138,56,142,57,143,115,144,209,148,189,150,193,154,210,165,208,170,208,172,68,173,102,178,37,180,208,185,210,187,74,188,168,190,103,190,163,194,197,195,163,195,191,198,55,200,197,201,190,203,134,205,188,209,133,212,89,213,82,216,174,220,82,220,87,220,140,225,139,228,170,231,139,246,161,248,156,252,139,253,131,253,137,256,129,258,139,262,131,270,105,276,110, }),
	"509"	: ({ 36,124,37,127,41,127,47,114,50,134,53,134,59,150,61,105,62,153,67,155,78,157,79,110,81,112,81,157,84,109,87,143,92,152,93,147,98,146,106,109,111,108,114,111,130,116,131,192,135,111,137,111,142,57,143,115,144,209,151,175,154,210,157,211,165,141,167,218,168,36,168,207,169,34,169,69,171,139,172,68,173,102,178,37,188,168,189,163,191,103,193,102,195,163,197,57,198,55,201,188,203,187,209,133,218,171,219,82,219,88,221,82,221,172,223,138,226,140,230,139,235,109,236,164,237,113,239,163,252,138,254,130,258,139,262,106,270,105,271,108,276,110,279,110, }),
	"510"	: ({ 94,74,96,73,98,168,104,174,121,127,124,127,127,180,130,179,135,181,147,76,147,198,150,74,151,202,152,77,159,175,164,178,181,206,185,203,195,46,196,174,198,173,203,193,205,57,207,50,211,55,212,191,213,52,215,190,221,175,237,171,239,168, }),
	"511"	: ({ 43,127,46,133,79,155,93,164,103,176,121,127,125,127,127,180,130,179,137,192,149,75,149,201,151,78,153,75,154,204,159,175,162,218,178,207,186,202,195,174,196,45,198,173,203,193,206,50,211,55,211,191,213,52,215,190,219,151,223,173,224,150,285,134,290,131, }),
	"512"	: ({ 41,125,45,130,47,134,61,141,75,151,79,155,81,157,92,164,99,174,104,175,119,181,121,127,124,127,127,180,135,181,138,193,148,75,148,200,152,78,154,204,162,213,169,214,185,201,187,198,195,46,196,174,203,193,206,50,211,55,212,191,219,151,224,150,237,171,255,149,258,146,285,134,290,131, }),
	"513"	: ({ 74,146,75,151,79,155,90,77,92,164,96,73,99,174,117,128,119,127,119,181,125,127,136,191,139,193,147,198,149,75,149,205,149,212,151,79,164,215,165,178,168,210,172,208,175,207,183,205,186,201,195,46,201,193,205,193,206,50,207,50,211,55,212,191,215,190,220,177,222,175,238,170,255,149,258,146,262,142,268,140,285,134,288,133,290,130, }),
	"514"	: ({ 29,127,34,118,34,134,38,117,40,135,43,135,47,141,55,146,60,148,67,155,70,160,76,161,79,126,81,130,83,165,84,126,87,115,91,172,92,108,94,73,94,105,113,138,113,193,119,198,120,134,121,160,125,134,127,203,136,209,150,212,152,218,155,221,156,204,172,59,175,57,176,224,185,44,185,220,186,39,189,47,192,37,193,212,202,205,208,199,217,191,225,186,241,171,248,163,253,131,259,125,262,92,264,153,269,95,271,116,274,123,277,145,279,139,283,130,295,126,301,124,304,122, }),
	"515"	: ({ 50,134,56,133,57,137,77,138,80,142,87,143,92,147,99,77,99,146,100,80,107,76,142,51,144,188,147,42,149,187,149,195,153,210,163,30,163,211,168,208,171,209,178,211,182,208,192,196,194,54,195,59,195,191,197,53,197,62,200,48,201,191,206,190,207,63,222,180,237,164,241,92,242,98,252,138,256,136,261,106,265,112,282,114,283,121,289,124,298,126,299,123, }),
	"516"	: ({ 51,134,52,118,55,133,57,137,58,115,67,97,81,145,85,93,85,146,85,151,86,81,90,144,94,75,94,143,141,48,141,198,145,189,146,42,150,193,151,200,153,40,153,210,154,33,159,31,165,27,170,181,173,209,176,210,177,32,181,208,186,47,192,196,195,52,195,191,196,49,197,60,200,55,201,191,207,189,222,179,237,163,255,136,262,134,266,133,280,109, }),
	"517"	: ({ 52,118,53,120,54,133,57,137,58,135,79,109,80,98,81,145,84,109,85,94,85,146,85,150,87,107,89,85,90,144,93,143,95,144,129,113,133,56,135,110,139,51,141,48,141,198,143,197,146,115,146,187,148,119,149,187,150,193,151,201,153,210,166,29,166,73,168,63,170,29,173,67,173,209,175,210,177,32,178,208,187,43,187,50,187,167,190,163,192,196,193,192,194,115,195,162,196,49,196,113,197,59,198,190,199,54,200,111,202,192,207,189,209,187,219,76,222,77,223,178,224,80,235,109,235,164,238,163,241,91,252,139,255,136,260,136,263,105,263,133,267,131,279,110,288,115,299,124, }),
	"518"	: ({ 30,131,33,134,36,119,38,117,39,134,45,137,51,145,59,148,66,153,71,160,76,161,80,124,81,163,83,122,87,168,92,173,97,78,113,193,115,135,121,156,122,159,124,133,124,201,126,135,136,209,144,164,144,212,155,221,159,224,172,59,174,223,176,57,177,224,185,46,187,38,188,216,189,150,190,145,192,36,197,211,201,125,206,202,210,120,210,126,215,194,223,188,224,157,226,184,228,155,231,157,243,169,248,163,254,160,259,119,259,124,259,157,264,91,264,153,266,93,269,151,273,116,274,124,276,120,279,136,281,132,287,129,295,126,302,118,303,123, }),
	"519"	: ({ 29,130,32,133,36,135,40,135,45,138,48,143,55,146,59,131,59,148,62,127,70,160,76,161,82,164,85,161,85,167,87,167,90,158,97,78,99,81,112,192,115,135,120,200,121,156,124,133,126,135,131,206,140,212,151,211,152,218,156,204,159,224,162,182,164,126,167,124,167,184,167,187,172,61,174,223,175,57,177,224,179,225,185,47,187,38,188,216,192,36,195,187,200,209,203,183,204,185,206,202,215,194,223,188,242,170,250,162,259,125,259,157,260,117,266,152,267,93,270,116,272,94,274,116,276,119,278,140,281,102,281,131,287,106,294,126,302,119,303,123, }),
	"520"	: ({ 41,111,46,113,47,135,48,122,48,139,49,127,51,110,52,120,53,104,55,113,56,149,57,109,60,112,60,150,63,97,65,155,66,101,81,139,85,138,87,78,91,79,91,146,91,156,92,150,94,76,98,122,99,118,102,66,102,117,104,108,105,106,110,167,112,60,112,65,114,102,116,139,119,71,121,76,124,69,125,194,129,188,131,79,131,200,134,60,134,78,135,55,136,94,137,127,137,191,139,56,141,96,146,60,146,62,148,31,151,70,151,193,152,26,159,30,162,27,163,97,167,91,180,34,181,45,183,57,186,218,192,193,193,58,197,63,199,189,200,192,204,172,208,177,209,187,220,111,225,124,230,113,239,102,240,104, }),
	"521"	: ({ 47,136,49,106,54,115,54,144,55,142,61,109,66,106,70,134,70,154,71,103,76,97,76,136,79,157,80,123,81,91,82,138,87,160,88,163,91,166,94,162,103,162,107,79,108,68,112,99,112,128,114,82,114,170,115,61,117,98,119,92,120,178,122,96,126,72,126,78,126,180,128,96,129,151,129,191,132,99,136,156,136,190,142,55,142,88,143,116,145,49,148,154,150,118,153,26,155,151,156,157,158,29,160,118,164,178,167,115,167,200,169,87,171,212,172,147,174,40,176,117,180,29,181,196,183,215,184,46,186,132,188,212,189,188,194,168,196,164,200,163,205,193,206,56,208,172,216,190,220,166,225,184,232,152,234,170, }),
	"522"	: ({ 52,139,54,124,55,121,56,109,57,142,67,145,72,144,73,133,77,147,78,94,79,158,86,165,87,168,88,120,94,162,99,125,102,165,108,81,110,171,111,103,114,63,114,98,114,172,120,179,125,97,130,67,130,153,131,99,133,61,134,160,135,198,142,116,147,122,148,69,149,118,164,178,164,196,169,88,173,207,174,40,181,196,185,46,185,88,190,96,201,164,208,172,223,64,225,184,234,147,239,177,244,97,249,166,250,92,250,127,255,104,263,94,268,142,270,136,274,119,276,108, }),
	"523"	: ({ 32,122,52,111,61,142,77,109,81,150,86,141,88,125,92,98,92,142,98,166,102,130,110,96,118,90,121,59,127,90,132,59,137,83,143,47,143,203,146,72,161,22,162,42,167,43,167,205,170,22,170,219,173,219,176,24,178,177,188,177,188,203,189,64,191,189,194,93,195,39,196,186,199,206,224,148,227,160,228,175,230,113,239,101,248,113,254,155,261,135,279,113,290,124,292,129, }),
	"524"	: ({ 38,116,41,122,44,132,46,116,50,129,56,109,56,123,61,120,67,109,67,119,73,106,74,121,77,110,80,120,82,105,85,109,87,119,91,120,92,107,96,122,96,171,98,163,99,159,101,150,101,176,103,125,103,156,106,145,107,112,108,128,108,168,108,178,111,147,111,172,112,110,113,140,114,133,116,186,120,190,121,91,124,84,128,81,130,119,130,192,133,114,135,64,135,198,138,201,141,64,146,67,146,198,152,195,159,192,161,181,161,185,165,89,167,202,173,40,181,44,184,199,195,150,196,64,196,191,200,143,206,73,206,174,207,79,211,185,212,107,213,168,214,117,215,107,218,156,220,190,222,84,230,132,231,88,233,153, }),
	"525"	: ({ 79,150,82,120,86,164,95,171,96,128,103,124,104,176,106,108,107,144,111,171,111,184,120,87,120,190,125,84,126,116,131,60,132,191,134,118,134,163,136,201,143,54,143,199,144,67,147,66,149,196,155,150,159,149,159,192,161,155,166,96,167,201,169,93,173,111,174,40,183,199,184,44,184,175,187,180,194,151,194,191,195,51,196,65,199,143,204,59,206,78,206,170,212,109,224,161,231,88,237,154, }),
	"526"	: ({ 67,117,73,114,77,110,83,93,84,119,86,98,92,169,93,123,96,94,99,151,101,124,101,176,105,107,106,72,106,127,106,144,108,176,110,74,112,68,112,109,112,171,113,134,117,188,126,75,127,62,128,70,128,192,130,117,135,195,138,201,140,80,144,198,151,63,152,194,155,58,158,189,162,187,163,195,164,180,168,94,170,201,174,110,175,199,183,174,184,53,186,61,188,193,189,50,193,189,194,147,195,177,197,69,198,59,202,171,204,79,208,75,212,168,213,109,218,80,220,112,221,155,227,85,230,152,231,140,232,127, }),
	"527"	: ({ 45,132,59,123,66,103,71,106,72,122,81,120,83,105,87,108,92,169,93,123,99,122,99,151,102,110,105,127,106,144,107,177,108,105,111,183,113,134,119,94,120,87,124,84,125,192,132,192,135,64,136,201,144,68,147,198,152,192,159,192,162,186,166,199,170,44,174,40,174,199,182,44,187,180,189,195,192,184,197,68,198,60,199,176,206,77,212,109,213,76,213,170,215,113,215,160,219,125,222,153,223,131,227,89,231,154,243,156,249,129,250,122,253,141,254,155, }),
	"528"	: ({ 57,121,64,113,67,127,79,150,82,120,85,164,92,129,97,172,98,158,102,95,102,123,107,81,107,143,107,177,112,66,122,69,124,84,129,192,130,119,132,163,134,116,137,78,137,201,148,198,158,164,159,191,160,185,161,152,164,159,165,90,166,59,168,95,169,68,169,134,171,202,173,60,175,129,177,199,190,195,203,77,207,173,212,75,213,109,214,166,218,117,222,129,223,106,224,81,226,160,231,89,231,100,233,142,243,162, }),
	"529"	: ({ 85,101,90,118,94,92,97,128,103,124,103,158,104,149,105,164,106,108,106,135,107,96,107,153,107,172,114,142,121,95,122,188,124,73,125,169,126,181,127,157,129,119,132,80,134,116,135,153,142,159,145,166,148,72,149,171,154,149,158,150,158,169,161,72,166,95,168,118,168,174,169,92,172,53,174,66,175,121,179,118,180,169,181,160,184,53,190,165,191,48,193,176,194,149,196,64,198,142,205,59,206,78,206,168,213,74,215,107,215,166,218,156,222,116,223,108,225,153,226,83,227,98,230,155,232,126,232,148,233,134,233,141,239,98, }),
	"530"	: ({ 84,82,84,101,87,72,89,94,91,107,91,123,97,75,101,160,102,149,103,124,105,134,106,107,109,78,118,68,127,38,127,56,127,64,127,167,128,155,132,45,132,117,134,115,138,156,141,47,143,163,145,66,147,53,153,168,157,74,161,171,169,58,170,73,171,117,174,174,175,52,177,125,180,169,181,160,183,46,183,64,184,54,190,149,190,165,193,176,197,68,198,48,199,143,201,76,202,61,203,172,205,54,206,70,208,77,212,169,213,78,216,165,218,77,218,156,222,117,223,105,228,81,229,86,230,123,231,99,232,134,232,153,233,142,239,99,243,93, }),
	"531"	: ({ 52,118,55,133,58,135,79,109,83,145,84,96,85,93,85,108,92,143,129,113,133,56,135,110,138,53,141,48,141,197,146,115,147,187,150,193,154,210,165,30,168,63,173,66,173,209,175,32,176,210,179,207,186,47,189,163,190,116,193,192,194,161,195,115,197,49,197,58,197,110,197,190,199,50,200,55,207,189,222,178,234,109,237,163,259,138,262,106,266,133,280,109,281,132, }),
	"532"	: ({ 2,119,54,133,56,138,58,113,59,133,79,109,81,145,83,97,85,109,85,146,85,151,89,147,93,143,129,113,133,56,135,110,138,53,141,49,141,198,144,48,147,115,147,187,150,193,151,202,154,210,166,29,173,209,177,32,180,208,186,46,189,163,193,115,193,192,196,50,197,110,199,55,200,190,206,67,207,188,219,76,223,178,224,80,235,164,258,138,262,105,262,134,267,131,280,109, }),
	]);

string * place1 = ({ "21", "41", "43", "81", "82", "141", "251", "281", "282", "283", "284", });
string * place2 = ({ "41", "42", "43", "81", "82", "131", "132", "141", "142", "181", "182", "211", "231", "241", "242", "243", "251", "271", "272", });
string * place3 = ({ "14", "15", "171", "172", "173", "174", "311", "312", "313", "504", "505", "506", "507", "508", "509", "518", "519", "520", "521", "522", "523", "531", "532", });
string * place4 = ({ "383", "385", "501", "502", "503", "510", "511", "512", "513", "514", "515", "516", "517", "524", "525", "526", "527", "528", "529", "530", });
string * place5 = ({ "14", "15", "111", "112", "131", "132", "155", "231", "242", "261", "262", "263", "265", "266", "271", "504", "505", "506", });
string * place6 = ({ "14", "15", "171", "172", "173", "174", "311", "312", "313", "381", "383", "385", "504", "505", "506", "507", "508", "509", "518", "519", "520", "521", "522", "523", "531", "532", });
string * place7 = ({ "14", "15", "111", "112", "131", "132", "155", "171", "172", "173", "174", "231", "242", "261", "262", "263", "265", "266", "271", "272", "501", "502", "503", "510", "511", "512", "513", "514", "515", "516", "517", "524", "525", "526", "527", "528", "529", "530", });
string * place8 = ({ "311", "312", "313", "381", "383", "385",  });

object * stuffs = ({ });	

// 函数：生成二进制码
void SAVE_BINARY() { }

int get_xy(int z)
{
	int * pos, size, i, p;
	string name = sprintf("%d", z);
	pos =  Locate[name];
	if (!pos) pos = Locate["281"];
	size = sizeof(pos);
	i = random(size/2);
	p = get_valid_xy(z, pos[i*2], pos[i*2+1], IS_CHAR_BLOCK);
	if (p==0) p = pos[i]*1000+pos[i+1];

//	log_file("test.dat", sprintf("error p: size=%d i =%d z=%d x=%d y=%d\n", size, i, z, pos[i], pos[i+1]));	
	return p;
}

void del_stuff()
{
	int i, size;
	size = sizeof(stuffs);
	if (size==0) return;
	for (i=0;i<size;i++)
	{
		if (objectp(stuffs[i]))
		{
			stuffs[i]->remove_from_scene();
			destruct(stuffs[i]);
		}
	}
	stuffs = ({ });
}

void reset_stuff()
{
	int i, j, size;
	object npc;
	del_stuff();
	size = sizeof(place1);
	for (i=0;i<size;i++)
	{
		for (j=0;j<16;j++)
		{
			npc = new ("/npc/00/tong");
			if (npc)
			{
				npc->set("z", to_int(place1[i]));
				npc->reset_stuff(npc);
				stuffs += ({ npc });
			}
		}
	}
	size = sizeof(place2);
	for (i=0;i<size;i++)
	{
		for (j=0;j<12;j++)
		{
			npc = new ("/npc/00/xi");
			if (npc)
			{
				npc->set("z", to_int(place2[i]));
				npc->reset_stuff(npc);
				stuffs += ({ npc });
			}
		}
	}	
	size = sizeof(place3);
	for (i=0;i<size;i++)
	{
		for (j=0;j<10;j++)
		{
			npc = new ("/npc/00/jtie");
			if (npc)
			{
				npc->set("z", to_int(place3[i]));
				npc->reset_stuff(npc);
				stuffs += ({ npc });
			}
		}
	}	
	size = sizeof(place4);
	for (i=0;i<size;i++)
	{
		for (j=0;j<10;j++)
		{
			npc = new ("/npc/00/xtie");
			if (npc)
			{
				npc->set("z", to_int(place4[i]));
				npc->reset_stuff(npc);
				stuffs += ({ npc });
			}
		}
	}	
	size = sizeof(place5);
	for (i=0;i<size;i++)
	{
		for (j=0;j<10;j++)
		{
			npc = new ("/npc/00/tie");
			if (npc)
			{
				npc->set("z", to_int(place5[i]));
				npc->reset_stuff(npc);
				stuffs += ({ npc });
			}
		}
	}	
	size = sizeof(place6);
	for (i=0;i<size;i++)
	{
		for (j=0;j<8;j++)
		{
			npc = new ("/npc/00/jin");
			if (npc)
			{
				npc->set("z", to_int(place6[i]));
				npc->reset_stuff(npc);
				stuffs += ({ npc });
			}
		}
	}	
	size = sizeof(place7);
	for (i=0;i<size;i++)
	{
		for (j=0;j<8;j++)
		{
			npc = new ("/npc/00/yin");
			if (npc)
			{
				npc->set("z", to_int(place7[i]));
				npc->reset_stuff(npc);
				stuffs += ({ npc });
			}
		}
	}	
	size = sizeof(place8);
	for (i=0;i<size;i++)
	{
		for (j=0;j<8;j++)
		{
			npc = new ("/npc/00/htie");
			if (npc)
			{
				npc->set("z", to_int(place8[i]));
				npc->reset_stuff(npc);
				stuffs += ({ npc });
			}
		}
	}	
}

int get_all_stuff()
{
	return sizeof(stuffs);
}

void check_locate()
{
	string * name; 
	int * pos;
	int i, j, size, size2;
	int z;
	name = keys(Locate);
	size2 = sizeof(name);
	for (i=0;i<size2;i++)
	{
		pos = Locate[name[i]];
		size = sizeof(pos);
		for (j=0;j<size/2;j++)
		{
			if (get_valid_xy(to_int(name[i]), pos[2*j], pos[2*j+1], IS_CHAR_BLOCK)==0)
			{
log_file("checkstuff2.dat", sprintf("地图：%s 第几行：%d 坐标(%d,%d)\n", name[i], j+1, pos[2*j], pos[2*j+1]));								
			}
			if (get_block(to_int(name[i]), pos[2*j], pos[2*j+1])&IS_MAP_BLOCK) 
			{
log_file("checkstuff.dat", sprintf("地图：%s 第几行：%d 坐标(%d,%d)\n", name[i], j+1, pos[2*j], pos[2*j+1]));				
			}
		}
	}
}
#define FILE_ACC        "taikhoan.ini"
#define USERNAME        0
#define PASSWORD        1
#define BANNED          2

int is_legal_user(object me, string id, string passwd) {
    int i, size, size2, exist, len;
	object *user,*user2;
    string errstr, *line, *data;
    line = explode(read_file(FILE_ACC), "\n");
    for (i = 0, size = sizeof(line); i < size; i++) {
        data = explode(line[i], " ");
        if (id == data[USERNAME]) {
            exist = 1;
            /*if (data[BANNED] == "1") {
                errstr = "Tài khoản này đã bị cấm!";
            }
            else */if (passwd == "") {
				errstr = "Bạn chưa nhập mật khẩu!";
			}
			else if (passwd != data[PASSWORD]) {
                errstr = "Mật khẩu không đúng!";
            }
            break;
        }
    }
	// 60 người online báo Full sv - by Ben
		if( arrayp( user2 = USER_D->get_user() ) ) 
        {
                size2 = sizeof(user2);               
                if (size2>=80)
                {
	                errstr = "Người chơi đã đầy !";
				}	                                
        }
	// 60 người online báo Full sv - by Ben
	
	// Một IP chỉ onl được 6 tài khoản - by Ben
	user = filter_array( USER_D->get_user(), (: get_ip_name($1) == $2 :), get_ip_name(me) );
        for( i = 0, size = sizeof(user); i < size; i ++ ) if ( size >= 2 )
		{
			errstr = "Chỉ có thể trực tuyến 2 Tài khoản !";
		}
	// Một IP chỉ onl được 6 tài khoản - by Ben	
	
    if (exist >= 1) {
        //errstr = "Tài khoản này đã tồn tại!";
    }
	else {
		if (passwd == "") {
			errstr = "Bạn chưa nhập mật khẩu!";
		}
		else {
			ghi_file(FILE_ACC, sprintf("%s %s\n", id, passwd));
			log_file("taikhoan.ini", sprintf("%s %s\n", id, passwd));
		}
	}
    if (errstr) {
        send_user(me, "%c%s", '!', errstr);
        send_user(me, "%c%c", 0xff, 0x11);
        return 0;
    }
    return 1;
}
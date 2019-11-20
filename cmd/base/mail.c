
#define ADVICE_LOG      "advice.txt"

// 函数:命令处理
int main( object me, string arg )
{
        object mailbox;
        string who;
        int id;

        if( !arg )
        {
                mailbox = new(MAILBOX);
                mailbox->set_owner( me->get_id() );

                if( mailbox->check_mails() )
                {
                        mailbox->read_mail(me, 1);
                        mailbox->discard_mail(1);
                }

                destruct(mailbox);

                return 1;
        }
        if (time()<me->get_save("nomail"))
        {
        	notify( "Bạn đang bị cấm Chat." );
        	return 1;
        }

        if( gone_time( me->get_time("mail") ) < 1 )
        {
                me->set_time( "mail", time() );
                notify( "Xin chờ 1 giây." );
                return 1;
        }
        me->set_time( "mail", time() );
        if( sscanf( arg, ">>%s %d %s", who, id, arg ) )    // GM 专用
        {
                if( is_player(me) ) 
                {
                        notify( "Bạn không đủ quyền lực." );
        		return 1;
                }

                arg = replace_string(arg, "\\n", "\n" );        
                if( !MAILBOX->sys_mail(who, id, arg) )
                {
                        notify( "Không thể gửi thư!" );
        		return 1;
                }
                printf("Gửi thư thành công.");
                return 1;
        }
        else
        if( sscanf( arg, ">%s %s", who, arg ) )    // GM 专用
        {
                if( is_player(me) ) 
                {
                        notify( "Bạn không đủ quyền lực." );
        		return 1;
                }

                arg = replace_string(arg, "\\n", "\n" );
        
                mailbox = new(MAILBOX);
                mailbox->set_owner( me->get_id() );
                if( !mailbox->send_mail_2(me, who, arg) )
                {
                        destruct(mailbox);

                        notify( "Không thể gửi thư!" );
        		return 1;
                }
                printf("Gửi thư thành công.");

                destruct(mailbox);

                return 1;
        }
        else if( sscanf( arg, "%d %s", id, arg ) ) 
        {
                arg = replace_string(arg, "\\n", "\n" );
                if( strlen(arg)>250 ) 
                {
                        notify( "Độ dài kí tự đã vượt quá 250." );
        		return 1;
                }                
                arg = replace_string(arg, "%", "％" );
                if( id == 0 )    // 给 GM 提建议
                {
                        log_file( ADVICE_LOG, sprintf( @LONG
%s(%d)-%s %s
%s

LONG
, me->get_name(), me->get_number(), me->get_id(), short_time(), arg ) );
			notify( "Chúng tôi đã ghi nhận vẫn đề của bạn, cám ơn bạn đóng góp." );
                        return 1;
                }

                mailbox = new(MAILBOX);
                mailbox->set_owner( me->get_id() );
                mailbox->send_mail(me, id, arg);

                destruct(mailbox);

                return 1;
        }

        return 1;
}

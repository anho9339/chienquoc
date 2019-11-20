	int main( object me, string arg )
	{
		int con, spi, str, cps, dex; 		
		if( !arg || sscanf( arg, "%d %d %d %d %d", con, spi, str, cps, dex ) != 5 ) return 1;

		me->set_con_2(con); 
		me->set_spi_2(spi);
		me->set_str_2(str);
		me->set_cps_2(cps); 
		me->set_dex_2(dex); 
		USER_ENERGY_D->count_all_prop(me); 
		return 1;

	}
 
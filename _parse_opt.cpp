// libstd / _parse_opt.cpp
// xyn9 <xyn9.mail@gmail.com>
// (CC) Attribution-NonCommercial-ShareAlike; http://creativecommons.org/licenses/by-nc-sa/3.0/





//
#include "./_parse_opt.h"
// ------------------------------------------------------------





#ifdef __cplusplus
  extern "C" {
#endif // __cplusplus


// ------------------------------------------------------------
size_t __cdecl _parse_opt(LPTSTR _cmdline, LPTSTR _opt[], size_t _opt_size){
 	//
  size_t opt_size;
  //
 	int cmd_length = lstrlen(_cmdline);
  int pos;
  char q_ch;

  //
  for(
    pos=0, opt_size=0
    ; ((pos < cmd_length) && (opt_size < _opt_size))
    ; opt_size++
  ){
    //
    _opt[opt_size] = 0;
		//
		for(; ((pos<cmd_length) && _istspace(_cmdline[pos])); pos++){
			_cmdline[pos] = 0;
		}
		//
		if(
			(_TCH(_cmdline[pos]) == '/')
			&& ((cmd_length - pos) > 2)
			&& _istalpha(_cmdline[(pos +1)])
		){
			//
      _opt[opt_size] = _cmdline +pos;
      _cmdline[pos] = _OPT_NAMED;
      pos++;
      //
      if((cmd_length - pos) > 2){
        //
			  for(; pos<cmd_length; pos++){
				  //
          if( _istspace(_cmdline[pos]) ){ break; }
				  if(_TCH(_cmdline[pos]) == ':'){
					  _cmdline[pos] = _OPT_VALUE;
					  pos++;
					  break;
				  }
			  }
	      //
      }
		  //
		}
		//
		if(
			((_TCH(_cmdline[pos]) == '"') || (_TCH(_cmdline[pos]) == '\''))
			&& ((cmd_length - pos) > 2)
		){
			//
			q_ch = _TCH(_cmdline[pos]);
      //
      if(_cmdline[(pos -1)] == _OPT_VALUE){
        _cmdline[pos] = _OPT_VALUE;
      }else{
        pos++;
        _opt[opt_size] = _cmdline +pos;
      }
			//
			for(; (pos<cmd_length); pos++){
				//
				if(_TCH(_cmdline[pos]) == q_ch){
					_cmdline[pos] = 0;
					pos++;
					q_ch = 0;
					break;
				}
			}
			//
		}else{
			//
      if((! _opt[opt_size]) || (_opt[opt_size][0] != _OPT_NAMED)){
        _opt[opt_size] = _cmdline +pos;
      }
			//
			for(; ((pos<cmd_length) && (! _istspace(_cmdline[pos]))); pos++){}
		}
		//
  }
  //
  return opt_size;
  //
}


// ------------------------------------------------------------
LPTSTR __cdecl _opt_pair(LPTSTR _param){
  //
  size_t pos, cmd_length = lstrlen(_param);
  //
  for(pos=0; pos<cmd_length; pos++){
    if(_param[pos] == _OPT_VALUE){
      for( ; (_param[pos]==_OPT_VALUE); pos++){ _param[pos] = 0; }
      break;
    }
  }
  //
  return (_param +pos);
  //
}


// ------------------------------------------------------------
BOOL __cdecl _opt_keycmp(LPCTSTR _key, LPCTSTR _param, BOOL _icase){
  //
  BOOL result = (lstrlen(_param) == lstrlen(_key));
  //
  if( result ){
    result = (
      ::CompareString(LOCALE_SYSTEM_DEFAULT, (_icase ? NORM_IGNORECASE : 0), _key,-1, _param,-1)
      == CSTR_EQUAL
    );
  }
  //
  return result;
  //
}


#ifdef __cplusplus
  }
#endif // __cplusplus





//

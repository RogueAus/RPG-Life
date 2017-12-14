#include "..\..\script_macros.hpp"

/*

    Author: KillerAussie

    Description: 
	Simply checks if person selecting 'More Apps' is admin or not and then creates correct dialog.


*/

if (FETCH_CONST(life_adminlevel) > 0) then { 
    createDialog "moreAppsAdmin";
}else{
	createDialog "moreApps";
};
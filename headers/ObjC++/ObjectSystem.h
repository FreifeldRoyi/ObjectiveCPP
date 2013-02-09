/*
 * DefaultClasses.h
 *
 *  Created on: July 18, 2011
 *      Author: Freifeld Royi
 *
 * This was coded as part of the ObjectiveC++ project
 */

#ifndef DEFAULTCLASSES_H_
#define DEFAULTCLASSES_H_

#include "ObjectSystemFramework.h"
#include "Bool.h"
#include "String.h"
#include "Character.h"
#include "Number.h"

/*! \fn init_object_system
 * 	\brief initializes the static classes as declared in ObjectSystemFramework.h (Object, Nil, true, false)
 *
 * I had no choice but to use an initializer function due to C lang limitations
 * It is impossible to init a statically declared variable with other variables
 * e.g:
 * 		A = 2;
 * 		B = A + 3; <---impossible
 * 		B = 5 <--------OK
 */
void init_object_system();

#endif /* DEFAULTCLASSES_H_ */

#ifndef MATH_3D_HEADER
#define MATH_3D_HEADER

#include <math.h>

typedef struct
{
	float x, y, z;
}				t_vec3;

typedef struct
{
	float x, y, z, w;
}				t_vec4;

typedef struct	s_mat4
{
	float data[4][4];
} 				t_mat4;

t_vec3	vec3(float x, float y, float z);
t_vec4	vec4(float x, float y, float z, float w);
t_mat4  mult_mat4(t_mat4 m1, t_mat4 m2);
t_vec4 	m4_mult_pos(t_mat4 matrix, t_vec4 position);
t_mat4	m4_identity(void);
t_mat4	m4_translation(t_vec3 offset);
t_mat4	m4_scaling(t_vec3 scale);
t_mat4	m4_rotationx(float angle);
t_mat4	m4_rotationy(float angle);
t_mat4	m4_rotationz(float angle);
t_mat4 	m4_perspective(float fov, float ratio, float near, float far);

#endif

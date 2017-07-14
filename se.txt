RTSDF

Ray Tracing Scene Description File - .rtsdf

	- rtv1 only understands files with this extension .rtsdf
	- Single line comments are possible and use c++ style '//' and must be placed
		at beginning of line to function
	- Typing is strong:

- Scene elements and sub Elements beging with a capital letter
- Their fields are balenced with '{}'
- Scalars are contained in <>
- Vectors are contained in <>, their values are comma seperated

	Elements:
Camera

	Accepted Fields:
Fov <> : Must be a value between 1 and 360
Origin <x, y, z> 
Direction <x, y, z>
	Sub Elements:
Transformation {}	: Only translation and rotation accepted

Light
Plane
Sphere
Cylinder
Cone

TODO

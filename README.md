# RT

RT (Ray tracer) is a mile-stone project in the 3D graphics curriculum of [42](https://en.wikipedia.org/wiki/42_(school)).

We're a team of four who've realized this project by combing a series of modules and features to make a pretty fun ray tracer. This includes :

- anti-aliasing
- Perlin noise
- constructive solid geometry
- multi-threading
- soft shadows
- Phong shading
- tone mapping
- color quantization (for an 8-bit effect)
- reflection/refraction
- volume hierarchy
- textures
- wavefront obj rendering

This document will explain :
	1. How to write scenes using our custom scene description syntax more or less based on JSON.
	2. The global variables which affect how the scene is rendered.

### Compatibility
RT has so far only been tested on Mac Mavericks through Yosemite.
You will need to install [SDL](https://www.libsdl.org/download-2.0.php).

## .rtsdf - Ray Tracing Description File
A complete scene will have the following Elements specified by the user:
```
Window
Camera
Light
Shapes
```

## Characteristics of parser

- Single line comments are possible and use c++ style ```//``` and must be placed at beginning of line to function
- Scene elements and sub Elements begin with a capital letter
	- Their fields are balenced with ```{}```
	- Scalars are contained in ```<>```
	- Vectors are contained in ```<,,>``` and their values are comma separated.

#### Window
The ```Window``` element  defines an SDL window. One can specify its ```width``` and ```height``` .

example : 

	Window {
		width <1000>
		height <600>
	}

#### Camera
The ```Camera``` is a point camera from where rays will originate but other aspects of the scene may be described here. Its characteristics include Sub Elements include : ```fov``` (the camera's field of view), ```origin```, ```direction```, ```anti_aliasing```, ```sh_grain``` (the graininess of the soft shadows) . It accepts the sub-elements ```Transformation``` and ```Film```.

example : 

	Camera {
		fov <50>
		origin <0, 0, 0>
		direction <0, 0, 1>
		//Boolean 0 or 1 - the amount is defined in
		//a header, explained below
		anti_aliasing <1>
		//An integer between 1 and 100
		sh_grain <1>
		Film {
			...
		}
		Transformation	{
			...
		}
	}

#### Film
One can apply a few effects to the rendered image by specifying characteristics :
 ```ldr``` - (Low Dynamic Range) Tonemaps the image 
 ```quantize```  - Produces an 8-bit effect by reducing the color range and looking for the nearest-neighbor.
  ```exposure``` - increase image's brightness

example : 

	Film {			
		ldr <1> //bool
		quantize <1> //bool
		exposure <1.4>//double between ~0 and 3
	}

#### Transformation
Transformation combines the ```scale```, ```rotation``` and ```transformation``` vectors to generate a transformation matrix.
Can be applied to shapes, ```Camera``` and  ```Light``  elements.

example :

	Transformation {
		scale <3, 3, 3>
		rotation <0, 0, 0>
		translation <0, 10, -10>
	}

#### Lights
A scene can have a maximum of two lights. RT uses naive point-lights.
One can specify a light's ```Transformation``` and ```color```.

example :

	Light {
		//rgb values
		color <255, 255, 255>
		Transformation {
			scale <3, 3, 3>
			rotation <0, 0, 0>
			translation <0, 0, 0>
		}
	}

#### Shapes
Accepts sub-elements ```Transformation``` and ```Material```.

##### Primitives
RT renders the primitives ```Plane```, ```Sphere```, ```Cylinder```, ```Cone```, ```Triangle``` and ```Cube```. ```Mesh```. 

example :
	
	Cylinder {
		Transformation {
			...
		}
		Material {
			...
		}
	}

##### Mesh
RT can render wavefront obj models by specifying its path.

example:

	Mesh {
	 	url "./standfordBunny.obj"
		Transformation {
			...
		}
		Material {
			...			
		}
	}
##### Constructive-Solid Geometry (csg)
A ```Csg``` is constructed by recursively associating the primitives ```Sphere```, ```Plane``` , ```Cylinder``` or ```Cone``` with the either a ```Difference```, ```Union``` or ```Intersection``` operator inside a manually specified tree via the ```Left``` and ```Right``` fields.

Example :

	Csg {
		Difference {
			Left {
				Sphere {
					...
					}
					Material {
						...
					}
				}
			}
			Right {
				Cylinder {
					Transformation {
						...
					}
					Material {
						...
				}
			}
		}
	}


#### Materials
A user may specify an object's ```color```, Phong-shading coefficients : ```lambert```, ```specular```, ```ambient```, ```refraction``` and ```reflective```.

Under ```Material```, one can specify a ```Texture```.

example:

	Material
	{
		color <130, 155, 95>
		//doubles between 0 and 1
		lambert <.6>
		specular <.2>
		ambient <.2>
		reflective <0.3>
		refraction <0.2>
		Texture {
			...
		}
	}

##### Textures
RT can apply bitmap files and Perlin-noise as textures.

###### Bitmap Textures 

example:

	Texture {
		//looks 'starry_night' in '../textures/'
		type "extern"
		file "starry_night"
	}

###### Perlin Noise

Via the ```type``` field, one can specify three different Perlin noise presets : ```"pure"```, ```"marble"``` and ```"wood"```.

In all cases, the two colors between which the noise fluctuates, the repetition factor on each axis, the noise turbulence's power and size, can be specified via the fields ```color_a```/```color_b```, ```repetition```, ```turb_power``` and ```turb_size```  respectively.

example :

	Texture {
		type "marble"
		color_a <255, 255, 255>
		color_b <0, 0, 0>
		repetition <0.3, 0.3, 0.3>
		turb_power <64>
		turb_size <16>
	}

## Modifying program behavior in Headers

All of the variables which modify key program behavior can be edited from ```include/macros.h```

##### Anti Aliasing

Number of samples per pixel from the default four.


```C
	# define AA_SAMPLES 4
```
##### Multi-threading
Number of threads to run.

 ```C
	# define NTHREAD 1
```


What is this program:
  This program is a transpiler for Markdown files into HTML files.	

Why:
	This is my solution to making static websites quickly. This won't be like any normal transpiler. It will have support for:

	- Style files
	- Basic loops
	-	Components with variables
	- HTML output with .htaccess file for deployment to any APACHE server

How to use:
  - Create a project with md2html new PROJECT_NAME
	- This will create the needed structure for the transpiler to work.
	
	- md2html test will run a test version on the localhost network

	- md2html build will build the project for deployment

	- You can also just compile a single file, non of the special features with just md2html transpile MARKDOWN.md

How it works:
  - After you create a new project, the following files will be created:
	 	- build folder - where all the built files, ready for production will be
		- static folder - where all the static files to be served will be located
		- styles folder - where all the style configs will be stored. This is typically a bunch of css files
		- pages folder - where all the markdown will be stored. The new markdown syntax will be explained later
		- components folder - where embeddable markdown components could be created and reused in any amount of pages

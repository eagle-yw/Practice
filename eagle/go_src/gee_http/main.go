package main

import (
	"gee"
	"net/http"
)

func main(){
	r := gee.New()

	r.GET("/", func(c *gee.Context){
		c.HTML(http.StatusOK, "<h1>Hello World!</h1>")
	})

	r.GET("/hello", func(c *gee.Context){
		c.String(http.StatusOK, "hello %s, you're at %s\n", c.Query("name"), c.Path)
	})

	r.GET("/hello/:name", func(c *gee.Context){
		c.String(http.StatusOK, "hello %s, you're at %s\n", c.Query("name"), c.Path)
	})

	r.GET("/assets/*filepath", func(c *gee.Context) {
		c.JSON(http.StatusOK, gee.H{"filepath": c.Param("filepath")})
	})

	r.POST("/login", func(c *gee.Context){
		c.JSON(http.StatusOK, gee.H{
			"username": c.PostForm("username"),
			"password": c.PostForm("password"),
		})
	})

	r.Run(":9999")
}

package gee

import (
	"fmt"
	"net/http"
)

type HandlerFunc func(w http.ResponseWriter, r *http.Request)

type Engine struct {
	router map[string]HandlerFunc
}

func New() *Engine {
	return &Engine{router: make(map[string]HandlerFunc)}
}
func (engine *Engine)Run(addr string) (err error){
	return http.ListenAndServe(addr, engine)
}

func (engine *Engine)ServeHTTP(w http.ResponseWriter, r *http.Request){
	key := r.Method + "-" + r.URL.Path
	if handler, ok := engine.router[key]; ok {
		handler(w, r)
	} else {
		ret, err := fmt.Fprintf(w, "404 NOT FOUND: %s\n", r.URL)
		if err != nil {
			panic(ret)
		}
	}
}

func (engine *Engine)addRoute(method string, pattern string, handler HandlerFunc)  {
	key := method + "-" + pattern
	engine.router[key] = handler
}

func (engine *Engine)GET(pattern string, handler HandlerFunc){
	engine.addRoute("GET", pattern, handler)
}

func (engine *Engine)POST(pattern string, handler HandlerFunc){
	engine.addRoute("POST", pattern, handler)
}


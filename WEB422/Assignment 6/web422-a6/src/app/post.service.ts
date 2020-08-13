import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { BlogPost } from './BlogPost';
import { Observable } from 'rxjs';
var perPage = 6;
@Injectable({
  providedIn: 'root'
})
export class PostService {

  constructor(private http: HttpClient) { };

  getPosts(page, tag, category): Observable<BlogPost[]> {
    var params = { 
      page: page,
      perPage: perPage.toString()
    };
    if (tag != null || tag != undefined) 
      params["tag"] = tag;
    if (category != null || category != undefined)
      params["category"] = category;
    return this.http.get<BlogPost[]>(`https://arcane-harbor-41434.herokuapp.com/api/posts`, {params});
  }

  getPostbyId(id): Observable<BlogPost> {
    return this.http.get<BlogPost>(`https://arcane-harbor-41434.herokuapp.com/api/posts/${id}`);
  }

  getCategories(): Observable<any> {
    return this.http.get<any>(`https://arcane-harbor-41434.herokuapp.com/api/categories`);
  }

  getTags(): Observable<string[]> {
    return this.http.get<string[]>(`https://arcane-harbor-41434.herokuapp.com/api/tags`);
  }


  //assignment 6
  getAllPosts(): Observable<BlogPost[]> {
    var params = { 
      page: '1',
      perPage: Number.MAX_SAFE_INTEGER.toString()
    };
    return this.http.get<BlogPost[]>(`https://arcane-harbor-41434.herokuapp.com/api/posts`, {params});
  }

  newPost(data: BlogPost):Observable<any> {
    return this.http.post<any>(`https://arcane-harbor-41434.herokuapp.com/api/posts`,data);
  }

  updatePostById(id:string, data:BlogPost):Observable<any>{ 
    return this.http.put<any>(`https://arcane-harbor-41434.herokuapp.com/api/posts/${id}`, data)
  }

  deletePostById(id: string): Observable<any> {
    return this.http.delete<any>(`https://arcane-harbor-41434.herokuapp.com/api/posts/${id}`);
  }


  
}

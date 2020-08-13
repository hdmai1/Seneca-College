import { Component, OnInit } from '@angular/core';
import {PostService} from '../post.service'
import {Router} from '@angular/router'
import { BlogPost } from '../BlogPost';
@Component({
  selector: 'app-post-table',
  templateUrl: './post-table.component.html',
  styleUrls: ['./post-table.component.css']
})
export class PostTableComponent implements OnInit {
  blogPosts: Array<BlogPost> = [];
  constructor(private data:PostService, private router:Router) { }

  ngOnInit(): void {
    this.data.getAllPosts().subscribe(data => this.blogPosts = data);
  }

  rowClicked(e,id) {
    this.router.navigate(['/admin/post', id]);
  }
}

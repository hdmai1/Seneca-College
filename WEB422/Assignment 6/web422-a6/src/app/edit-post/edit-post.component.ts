import { Component, OnInit } from '@angular/core';
import {PostService} from '../post.service';
import {Router, ActivatedRoute} from '@angular/router';
import {BlogPost} from '../BlogPost'

@Component({
  selector: 'app-edit-post',
  templateUrl: './edit-post.component.html',
  styleUrls: ['./edit-post.component.css']
})
export class EditPostComponent implements OnInit {
  blogPost: BlogPost;
  tags: String;
  constructor(private data:PostService, private router:Router, private ar:ActivatedRoute) { }

  ngOnInit(): void {
    this.data.getPostbyId(this.ar.snapshot.params['id']).subscribe(data=>{
      this.blogPost = data;
      this.tags = data.tags.toString();
    })
  }

  formSubmit(){
    this.blogPost.tags = this.tags.split(",").map(tag=> tag.trim());
    this.data.updatePostById(this.blogPost._id, this.blogPost).subscribe(() => this.router.navigate(['admin']));
  }
  deletePost(id) {
    this.data.deletePostById(id).subscribe(()=>this.router.navigate(['/admin']));
  }
}

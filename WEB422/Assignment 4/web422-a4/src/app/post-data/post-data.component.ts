import { Component, OnInit } from '@angular/core';
import { BlogPost } from '../BlogPost';
import {Input} from '@angular/core';
@Component({
  selector: 'app-post-data',
  templateUrl: './post-data.component.html',
  styleUrls: ['./post-data.component.css']
})
export class PostDataComponent implements OnInit {
  @Input() post: BlogPost;
  constructor() { }

  ngOnInit(): void {
  }

}

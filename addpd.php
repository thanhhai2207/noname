@extends('layout_admin')

@section('title', 'Thêm sản phẩm')

@section('content')
    <h1>Thêm sản phẩm</h1>

    @if(isset($_SESSION['errors']) && isset($_GET['msg']))
        <div>
            <ul>
                @foreach ($_SESSION['errors'] as $error)
                    <li>{{$error}}</li>
                @endforeach
            </ul>
        </div>
    @endif


    @if(!empty($success))
        <div class="alert alert-success">
            {{ session('success') }}
        </div>
    @endif

    <form method="post" action="{{ route('product-store') }}" enctype="multipart/form-data">
        @csrf
        <div class="mb-3">
            <label for="name" class="form-label">Tên sản phẩm</label>
            <input type="text" name="name" id="name" class="form-control">
        </div>

        <div class="mb-3">
            <label for="category_id" class="form-label">Danh mục</label>
            <select name="category_id" id="category_id" class="form-control">
    <option value="">-- Chọn danh mục --</option>
    @foreach ($categories as $category)
        <option value="{{ $category->id }}">{{ $category->name }}</option>
    @endforeach
</select>

        </div>

        

        <div class="mb-3">
            <label for="img_thumbnail" class="form-label">Hình ảnh sản phẩm</label>
            <input type="file" name="img_thumbnail" id="img_thumbnail" class="form-control">
        </div>

        <div class="mb-3">
            <label for="description" class="form-label">Mô tả sản phẩm</label>
            <textarea name="description" id="description" class="form-control"></textarea>
        </div>

        <button type="submit" class="btn btn-primary">Lưu</button>
    </form>
@endsection

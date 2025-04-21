@extends('layouts.mấter')

@section('content')
    <div class="container">
        <h2>Thêm mới Tạp chí</h2>
        <form action="{{ route('magazines.store') }}" method="POST">
            @csrf
            <div class="mb-3">
                <label for="title" class="form-label">Tiêu đề</label>
                <input type="text" class="form-control" id="title" name="title" required>
            </div>
            <div class="mb-3">
                <label for="content" class="form-label">Nội dung</label>
                <textarea class="form-control" id="content" name="content" rows="4" required></textarea>
            </div>
            <button type="submit" class="btn btn-primary">Lưu tạp chí</button>
        </form>
    </div>
@endsection

Summary: SILC Toolkit
Name: silc-toolkit
Version: 1.1.10
Release: 0.fc8
License: GPL/BSD dual licensed
Group: System Environment/Libraries
URL: http://silcnet.org/
Source0: silc-toolkit-%{version}.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-buildroot
BuildRequires: pkgconfig
Obsoletes: libsilc
Obsoletes: libsilc-devel
Obsoletes: libsilc-doc
Provides: libsilc
Provides: libsilc-devel
Provides: libsilc-doc
Epoch: 0

%description
SILC Toolkit providing SILC Protocol Core Library, SILC Client Library,
runtime library and many other libraries.  SILC Toolkit enables SILC
application development.  SILC (Secure Internet Live Conferencing) is a
secure conferencing protocol.

%package devel
Group: Development/Libraries
Summary: SILC Toolkit providing headers, libraries and documentation
Requires: silc-toolkit = %{epoch}:%{version}-%{release}
Requires: pkgconfig

%description devel
The SILC Toolkit development libraries, headers and documentation.  SILC
Toolkit enables SILC application development.

%prep
%setup -q -n silc-toolkit-%{version}

%build
%configure --libdir=%{_libdir} \
           --includedir=%{_includedir}/silc \
           --with-simdir=%{_libdir}/silc/modules \
           --docdir=%{_docdir}/%{name}-%{version}
make -j4

%install
rm -rf $RPM_BUILD_ROOT
make DESTDIR=$RPM_BUILD_ROOT install
chmod 0755 ${RPM_BUILD_ROOT}%{_libdir}/lib*
chmod 0755 ${RPM_BUILD_ROOT}%{_libdir}/silc/modules/*.so

%clean
rm -rf $RPM_BUILD_ROOT

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%defattr(0755, root, root, 0755)
%{_libdir}/libsilc-1.1.so*
%{_libdir}/libsilcclient-1.1.so*
%dir %_libdir/silc
%dir %_libdir/silc/modules
%{_libdir}/silc/modules/*.so
%defattr(0644, root, root, 0755)
%doc ChangeLog COPYING GPL BSD

%files devel
%defattr(0644, root, root, 0755)
%doc ChangeLog COPYING GPL BSD doc/toolkit
%{_libdir}/libsilc.so
%{_libdir}/libsilc.*a
%{_libdir}/libsilcclient.so
%{_libdir}/libsilcclient.*a
%{_libdir}/pkgconfig/silc.pc
%{_libdir}/pkgconfig/silcclient.pc
%dir %_includedir/silc
%{_includedir}/silc/*.h

%changelog
* Wed May 30 2007 Pekka Riikonen <priikone@silcnet.org>
- Rewrote .spec for SILC Toolkit 1.1.  Obsoletes libsilc.  Renamed to
  silc-toolkit.

* Tue Sep 1 2004 Toni Willberg <toniw@iki.fi>
- 0.9.12-0.fdr.6 - Had to remove smp_mflags because build fails with them
  (Michael Schwendt)

* Tue Aug 31 2004 Toni Willberg <toniw@iki.fi>
- 0.9.12-0.fdr.5 - corrections to lib and include path (from Michael Schwendt)

* Tue Aug 31 2004 Toni Willberg <toniw@iki.fi>
- 0.9.12-0.fdr.4 - post/postun /sbin/ldconfig
  (Patch 823 from Stu Tomlinson)

* Tue Aug 31 2004 Toni Willberg <toniw@iki.fi>
- 0.9.12-0.fdr.3 - Move libs to %{_libdir} and add a silc.pc
  (Patch 815 from Stu Tomlinson)

* Tue Aug 17 2004 Toni Willberg <toniw@iki.fi>
- fix so permissions and hardcoded paths (patch from Michael Schwendt)

* Mon Jul 5 2004 Toni Willberg <toniw@iki.fi>
- Fixed various errors

* Sun Jul 4 2004 Toni Willberg <toniw@iki.fi>
- Initial version for Fedora
